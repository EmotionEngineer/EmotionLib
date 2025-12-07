# EmotionLib
### Efficient Library for Media Content Analysis

[![GitVerse Mirror](https://img.shields.io/badge/GitVerse-Mirror-blue?style=for-the-badge&logo=git&logoColor=white)](https://gitverse.ru/kill/emotionlib)

![Demo 1](https://raw.githubusercontent.com/EmotionEngineer/EmotionLib/master/Demo/1.png)
![Demo 2](https://raw.githubusercontent.com/EmotionEngineer/EmotionLib/master/Demo/2.png)

**EmotionLib** is a robust C library designed for media content analysis. It identifies and blocks unsafe content while enhancing recommendations for safe media. By classifying content and analyzing emotional tone, the solution provides deeper insights into media sentiment and ensures a safer, more engaging user experience.

The library is optimized for high performance and compatibility with various architectures, including **x86_64**, **ARM**, and **E2K (Elbrus)**.

---

## Key Features & Application Areas

- **Sentiment Analysis** – detect emotional tone (positive / neutral / negative) in images and video frames.
- **Content Classification** – detect sensitive content such as nudity, sexual content, and graphic violence.
- **NSFW / Gore Blocking** – compute a safety score and automatically block media that exceeds a configurable risk threshold.
- **MPAA‑style Rating Prediction** – predict an approximate MPAA rating (`G`, `PG`, `PG‑13`, `R`) for a video based on sequence analysis.
- **Recommendation & Ranking** – use safety and positiveness scores as additional signals for recommender systems and search ranking.
- **Parental Control & Moderation** – integrate into clients, players, or moderation tools to warn users or restrict playback for under‑age audiences.
- **Pure C Inference Core** – efficient CPU‑only inference in C with bindings to other languages (C#, etc.) via a stable C API.

---

## 🏆 Awards & Mentions

- **BRICS Awards 2024**
- **Softpedia**: [Editor's Review](https://www.softpedia.com/get/Multimedia/Video/Video-Players/EmotionPlayer.shtml)
- **ITMO AI Showcase**: [Project Page](https://ai.itmo.ru/projects)

---

## 🏗 System Architecture

The core logic consists of hybrid neural networks combining Convolutional Neural Networks (CNNs) for frame analysis and LSTM/MLP ensembles for temporal aggregation.

### Hybrid Model Pipeline (SAMP Component)

The following diagram illustrates how frame probabilities are aggregated and processed through parallel LSTM and MLP branches to produce a final safety score.

```mermaid
graph TD
    subgraph Input [Input Data]
        A[Frame Probabilities<br/>3 channels .efp, 1 channel .epp] --> B[Calculation]
        B --> C[53 Aggregated<br/>Statistical Features]
    end

    subgraph Branch1 [Branch 1: Time Series Analysis LSTM]
        A --> D[Select Central Sequence<br/>T=50 frames]
        D --> E[Tensor Formation<br/>50, 4]
        E --> F[LSTM Layer<br/>64 Hidden Neurons]
        F --> G[Last Step Output<br/>Vector 64]
    end

    subgraph Branch2 [Branch 2: Statistical Feature Analysis Ensemble]
        C --> H[53 Features]
        C --> I[53 Features]
        
        subgraph BaseEnsemble [Base Ensemble]
            H --> J1[model1]
            H --> J2[model2]
            H --> J3[model3]
            J1 --> K1[9 Interm. Features]
            J2 --> K2[3 Interm. Features]
            J3 --> K3[18 Interm. Features]
        end
        
        subgraph NewNAS [New NAS-MLP Module]
            I --> L1[Select 45 Features<br/>Excl. Energy/Slope]
            L1 --> L2[model4]
            L2 --> L3[20 Interm. Features]
        end
        
        K1 & K2 & K3 & L3 --> M[Concatenation of<br/>Intermediate Features]
    end

    M -- Unified Vector 50 --> N[Concatenation]
    G --> N
    
    subgraph FinalLayer [Final Classifier]
        N --> O[Combined Vector<br/>114]
        O --> P[Dense Layers<br/>Dense, BatchNorm, Tanh, Relu]
        P --> Q[Sigmoid Activation]
        Q --> R[Final Safety Score<br/>Probability 0 to 1]
    end
    
    style Input fill:#e1f5fe,stroke:#01579b,stroke-width:2px
    style Branch1 fill:#fff9c4,stroke:#fbc02d,stroke-width:2px
    style Branch2 fill:#e8f5e9,stroke:#2e7d32,stroke-width:2px
    style FinalLayer fill:#ffe0b2,stroke:#f57c00,stroke-width:2px
    style BaseEnsemble fill:#ffffff,stroke:#666,stroke-dasharray: 5 5
    style NewNAS fill:#ffffff,stroke:#666,stroke-dasharray: 5 5
```

### MLP Ensemble Architecture

Internal structure of the NAS‑found MLP architectures used in the statistical branch.

```mermaid
graph TD
    Input[Input: 53 Features]
    
    subgraph M1 [MLP 1 model1]
        direction TB
        Input --> L1_1[Input Layer: 53]
        L1_1 --> L1_2[Hidden 1: 32]
        L1_2 --> L1_3[Hidden 2: 26]
        L1_3 --> L1_4[Hidden 3: 9]
        L1_4 --> Out1[Output: 9]
        Out1 -.-> Unused1[Unused Final Out]
    end

    subgraph M2 [MLP 2 model2]
        direction TB
        Input --> L2_1[Input Layer: 53]
        L2_1 --> L2_2[Hidden 1: 32]
        L2_2 --> L2_3[Hidden 2: 26]
        L2_3 --> L2_4[Hidden 3: 3]
        L2_4 --> Out2[Output: 3]
        Out2 -.-> Unused2[Unused Final Out]
    end

    subgraph M3 [MLP 3 model3]
        direction TB
        Input --> L3_1[Input Layer: 53]
        L3_1 --> L3_2[Hidden 1: 32]
        L3_2 --> L3_3[Hidden 2: 26]
        L3_3 --> L3_4[Hidden 3: 18]
        L3_4 --> Out3[Output: 18]
        Out3 -.-> Unused3[Unused Final Out]
    end

    Out1 --> Concat[Concatenation]
    Out2 --> Concat
    Out3 --> Concat
    Concat --> Final[Ensemble Output: 30]

    style M1 fill:#f9f2c3,stroke:#d4c685
    style M2 fill:#c3f9e6,stroke:#85d4b3
    style M3 fill:#e6c3f9,stroke:#b385d4
    style Concat fill:#badc58,stroke:#6ab04c
```

### Low‑Level Implementation Details

The library uses a pure C implementation of neural network layers to ensure portability (including Elbrus E2K compatibility) and performance. Below are examples of the core math operations used in `filter.dll`.

<details>
<summary><b>Click to view C Source Code Elements (Convolution & ReLU)</b></summary>

```c
#include <math.h>
#include "filter_activation.h"

/*
 * Operand:           Conv
 * Name: filtermodel/stem_conv/Conv2D
 * Description: Standard 3x3 Convolution with stride 2 (Stem layer)
 */
LIB_HIDDEN void node_filtermodel_stem_conv_Conv2D(
    const float x[1][3][224][224],
    const float w[32][3][3][3],
    const float bias[32],
    float y[1][32][112][112]
)
{
    /* Conv
     * auto_pad: NOTSET
     * strides: 2 2 
     */
    for (uint32_t b = 0; b < 1; b++) {
        for (uint32_t m = 0; m < 32; m++) {
            for (int32_t o0 = 0, i0 = -1; o0 < 112; o0++, i0 += 2) {
                for (int32_t o1 = 0, i1 = -1; o1 < 112; o1++, i1 += 2) {
                    y[b][m][o0][o1] = bias[m];
                    for (int32_t c = 0; c < 3; c++) {
                        for (uint32_t k0 = 0; k0 < 3; k0++) {
                            for (uint32_t k1 = 0; k1 < 3; k1++) {
                                int ii0 = i0 + k0 * 1;
                                if (ii0 < 0 || ii0 >= 224) continue;
                                int ii1 = i1 + k1 * 1;
                                if (ii1 < 0 || ii1 >= 224) continue;
                                y[b][m][o0][o1] +=
                                    x[b][c][ii0][ii1] * w[m][c][k0][k1];
                            }
                        }
                    }
                }
            }
        }
    }
}

/*
 * Operand:           Relu
 * Name: filtermodel/stem_relu/Relu
 * Description: Rectified Linear Unit activation
 */
LIB_HIDDEN void node_filtermodel_stem_relu_Relu(
    const float X[1][32][112][112],
    float Y[1][32][112][112]
)
{
    float *X_ptr = (float*)X;
    float *Y_ptr = (float*)Y;
    for (uint32_t i = 0; i < 401408; i++)
        Y_ptr[i] = X_ptr[i] > 0 ? X_ptr[i] : 0;
}

/* 
 * Additional implementations (GlobalAveragePool, Sigmoid, etc.) are 
 * included in the source files to ensure dependency‑free compilation.
 */
```

</details>

---

## 🛠 Building the Library

### Minimal Technical Requirements

- **OS (core C library)**  
  - Linux (x86_64, ARM64, Elbrus E2K)  
  - Windows 10/11 (x86_64)
- **Compiler / Toolchain**  
  - Any C99‑compatible compiler 
  - `make` (for the provided Makefiles)
- **Hardware**  
  - CPU‑only, no GPU required  
  - ≥ 4 GB RAM recommended for typical video‑length processing

> Note: the examples using OpenCvSharp and .NET (see below) have additional runtime requirements (e.g. .NET 6+ or .NET Framework 4.7.2, Windows Media stack for EmotionPlayer).

### Build Steps

1. **Clone & Setup**

   ```bash
   git clone https://github.com/EmotionEngineer/EmotionLib.git
   cd EmotionLib
   ```

2. **Download Weights**

   Download `weights_headers.zip` from the
   [Releases](https://github.com/EmotionEngineer/EmotionLib/releases) page
   and extract the `*_weights.c` files into the corresponding folders:

   - `filter/` – CNN weights for the content filter
   - `positiveness/` – CNN weights for the positiveness model

3. **Compile**

   ```bash
   cd filter        && make CFLAGS=-fno-lto
   cd ../positiveness && make CFLAGS=-fno-lto
   cd ../samp       && make
   ```

   The resulting binaries will be something like:

   - `filter.so` / `filter.dll`
   - `positiveness.so` / `positiveness.dll`
   - `samp.so` / `samp.dll`

---

## 🚀 Integration Examples

### 1. Comprehensive C Integration Tester

A complete, compile‑ready example `tester/main.c` is provided in the repository. This tester serves as:

1. **Integration Example** – shows how to load the shared libraries and run the full pipeline.  
2. **Platform Validator** – used to verify compatibility on **Elbrus** and **Baikal** platforms.  
3. **Performance Benchmark** – simulates long‑running video processing.

**Location:** [`tester/main.c`](https://github.com/EmotionEngineer/EmotionLib/blob/master/tester/main.c)

**Compilation:**

```bash
# Linux / Elbrus / Baikal
cd tester
gcc main.c -o tester -ldl -lpthread -lm

# Windows (MinGW)
cd tester
gcc main.c -o tester.exe
```

**Preparing libraries for the tester:**

```bash
# Linux / Unix-like
cp ../filter/filter.so             ./filter.so
cp ../positiveness/positiveness.so ./positiveness.so
cp ../samp/samp.so                 ./samp.so

# Windows
copy ..\filter\filter.dll          .\filter.dll
copy ..\positiveness\positiveness.dll .\positiveness.dll
copy ..\samp\samp.dll              .\samp.dll
```

> The tester expects `filter`, `positiveness` and `samp` libraries
> (`.so` / `.dylib` / `.dll`, depending on platform) to be located in
> the **same directory** as the `tester` binary.

**Running:**

```bash
./tester        # Linux / Elbrus / Baikal
tester.exe      # Windows (MinGW)
```

If you see an error on Linux like:

```text
./tester: symbol lookup error: ./samp.so: undefined symbol: _ZGVbN2v_log
```

this usually means that `samp.so` was compiled against a **different (newer) glibc/libm/libmvec** than the one available on the **target system**. In this case, make sure to build **all three libraries** (`filter`, `positiveness`, `samp`) **directly on the target machine** (or in a container with the same glibc version), and then re‑run the tester.

---

### 2. C# / .NET Integration Snippets & Console Example

For .NET developers, EmotionLib can be accessed via P/Invoke. Minimal declarations:

```csharp
using System.Runtime.InteropServices;

// Import for Safety Analysis (SAMP)
[DllImport("samp.dll", CallingConvention = CallingConvention.Cdecl)]
public static extern double predictSAMP(string epp_path, string efp_path);

// Import for Frame Inference (Filter)
[DllImport("filter.dll", CallingConvention = CallingConvention.Cdecl)]
public static extern void filter_VideoInference(
    [In, Out] float[,,,] frames,
    int num_frames,
    [In, Out] float[,] results,
    IntPtr progress
);

// Import for Positiveness Analysis
[DllImport("positiveness.dll", CallingConvention = CallingConvention.Cdecl)]
public static extern void positiveness_VideoInference(
    [In, Out] float[,,,] frames,
    int num_frames,
    [In, Out] float[,] results,
    IntPtr progress
);
```

A complete working **.NET console example** is provided in:

- `Example/InferenceExample/Program.cs`

This example:

- loads videos from an `Input` folder using **OpenCvSharp4**,
- samples frames at a dynamic interval depending on video duration,
- runs `positiveness_VideoInference` and `filter_VideoInference` over batches of frames (CPU‑only),
- writes `.epp` and `.efp` binary feature files into an `Output` folder,
- calls `predictSAMP` to obtain a final safety / MPAA score and prints the result.

#### How to run `Example/InferenceExample`

1. **Build EmotionLib**

   Build the native libraries as described in [Building the Library](#-building-the-library), making sure to use **x64** if you target a 64‑bit .NET runtime.

2. **Build the C# example**

   Open the C# project (or create one referencing `Program.cs`) in Visual Studio or via `dotnet`:

   - Target framework: `.NET 6` (or similar)  
   - Add NuGet package: `OpenCvSharp4` (and optionally `OpenCvSharp4.runtime.win` on Windows)

3. **Copy native EmotionLib binaries next to the C# executable**

   On **Windows (x64)**, after building the C# project (Debug configuration):

   ```text
   Example/InferenceExample/bin/x64/Debug/
       InferenceExample.exe
       filter.dll
       positiveness.dll
       samp.dll
       OpenCvSharpExtern.dll   # from OpenCvSharp4.runtime.win
   ```

   On **Linux**, after building the C# project (e.g. `dotnet build`):

   ```text
   Example/InferenceExample/bin/Debug/netX.Y/
       InferenceExample
       filter.so
       positiveness.so
       samp.so
       libOpenCvSharpExtern.so   # from OpenCvSharp4.runtime.linux
   ```

4. **Prepare input data**

   Create an `Input` folder next to the executable and place your video files there:

   ```text
   Example/InferenceExample/bin/x64/Debug/
       InferenceExample.exe
       Input/
           video1.mp4
           video2.mkv
           ...
   ```

5. **Run the example**

   - On Windows: double‑click `InferenceExample.exe` or run from a console.
   - On Linux: `./InferenceExample`.

   The app will:

   - process all videos in the `Input` folder,
   - create an `Output` folder with `.epp` and `.efp` files,
   - print for each video:
     - the progress of positiveness and filter inference,
     - the final SAMP score and the corresponding MPAA‑style rating or `Unsafe`.

---

### 3. Desktop Video Player Demo (`EmotionPlayer`, C# / WPF)

A full Windows desktop application demonstrates how EmotionLib can be integrated into a real‑world video player with timeline visualization and MPAA‑style rating:

- Repository: **https://github.com/EmotionEngineer/EmotionPlayer**

**Key characteristics:**

- WPF video player based on `MediaElement` (Windows Media stack).
- Uses `positiveness.dll`, `filter.dll`, and `samp.dll` via P/Invoke.
- Samples frames every N seconds (depends on total duration) and visualizes positiveness on the timeline with happy/sad icons.
- Computes a final rating (`G`, `PG`, `PG‑13`, `R`) or `Unsafe` using SAMP.
- Stores intermediate results in `.epp` and `.efp` files inside an `Output` folder.

**Minimal requirements (EmotionPlayer):**

- OS: Windows 10/11 x64  
- Runtime: **.NET Framework 4.7.2**  
- Media stack: **Windows Media Player** installed (used by WPF `MediaElement`)

**Native library deployment for EmotionPlayer:**

After building EmotionLib for **x64** and EmotionPlayer in Release mode, place the native DLLs next to `EmotionPlayer.exe`, for example:

```text
EmotionPlayer/EmotionPlayer/bin/x64/Release/
    EmotionPlayer.exe
    filter.dll
    positiveness.dll
    samp.dll
    OpenCvSharpExtern.dll   # from OpenCvSharp4.runtime.win
```

Without these native DLLs, EmotionPlayer will start but will fail when trying to run inference.

Detailed build and usage instructions are available in the
[EmotionPlayer README](https://github.com/EmotionEngineer/EmotionPlayer).

---

## 🧪 Model Training & Reproducibility

We provide Jupyter notebooks and datasets to reproduce the training of the classification heads.  
*Note: The original raw video datasets are not distributed due to legal/safety restrictions. Feature extraction vectors are provided instead.*

### 1. Emotional Analysis (Positiveness)

The `positiveness.dll` module achieves **99.58% Accuracy** and **0.9999 AUC** on validation, ensuring high‑precision emotional context detection.

- **Training Notebook:**  
  [Kaggle: EmotionLib Positiveness Train](https://www.kaggle.com/code/saicourse/emotionlib-positiveness-train)
- **Accuracy:** >99% (validated on held‑out sets)

### 2. Safety Filter (NSFW / Gore)

The core safety mechanism uses an LSTM and NAS‑MLP ensembles over `.efp` / `.epp` features.

- **Training Notebook:**  
  [Kaggle: Filter Train (Additional Features)](https://www.kaggle.com/code/saicourse/emotionlib-filter-train-additional-features/)
- **Dataset:**  
  [EmotionLib Media Filter Dataset (Extended Intermediate)](https://www.kaggle.com/datasets/saicourse/emotionlib-media-filter-dataset-extended-inter)  
  *Contains:* Pre‑computed feature vectors from `filter` and `positiveness` for >8000 videos.

### 3. MPAA Rating Prediction

Multiclass classification for approximate MPAA ratings: `G`, `PG`, `PG‑13`, `R`.

- **Training Notebook:**  
  [Kaggle: MPAA Train](https://www.kaggle.com/code/saicourse/emotionlib-mpaa-train)
- **Dataset:**  
  [EmotionLib MPAA Rating Dataset](https://www.kaggle.com/datasets/saicourse/emotionlib-mpaa-rating-dataset)

---

## 📜 License

EmotionLib is released under the **MIT License**.  
See the [`LICENSE`](https://github.com/EmotionEngineer/EmotionLib/blob/master/LICENSE) file for details.
