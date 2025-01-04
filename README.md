# EmotionLib
### Efficient Library for Media Content Analysis

![Demo 1](https://raw.githubusercontent.com/EmotionEngineer/EmotionLib/master/Demo/1.png)
![Demo 2](https://raw.githubusercontent.com/EmotionEngineer/EmotionLib/master/Demo/2.png)

**EmotionLib** is a robust C library designed for media content analysis. It identifies and blocks unsafe content while enhancing recommendations for safe media. By classifying content and analyzing emotional tone, solution provides deeper insights into media sentiment and ensures a safer, more engaging user experience.

#### Key Features

- **Sentiment Analysis**: Detect emotional context from images or video frames.  
- **Content Classification**: Identify sensitive content like explicit material or violence.
- **MPAA Prediction**: Classify videos under the MPAA (Motion Picture Association of America) rating system based on frame analysis.
- **NSFW/Gore Blocking**: Block media content deemed unsafe for general audiences.
- **Easy Integration**: Seamless integration with applications, complete with usage examples.
- **Pure C Implementation**: Optimized for performance and compatibility.

#### Components

The library consists of three main components:

##### 1. `filter.dll`
Handles the classification of frames into three content categories:
- **Safe Content**  
- **Explicit Material**  
- **Violent Content**  

##### 2. `positiveness.dll`
Evaluates frames for emotional positivity/negativity. Useful for identifying negative or distressing emotions in non-sensitive content.

##### 3. `samp.dll`
Utilizes predictions from `filter.dll` and `positiveness.dll` for the following:
- **MPAA Rating Prediction**: Assigns a suitable MPAA rating (G, PG, PG-13, R) to the video based on frame-level analysis.  
- **NSFW/Gore Blocking**: Flags videos identified as unsafe (explicit or violent).  

#### Building the Library

- `filter.dll` is compiled using `make` from the `/filter` directory.
- `positiveness.dll` is compiled using `make` from the `/positiveness` directory.
- It is recommended to compile via `make CFLAGS=-fno-lto` to optimize the build time.

### Getting Started

#### Prerequisites
- C Compiler (GCC recommended)
- Make

#### Model Weights Headers

Before building the libraries, you need to download and set up the model weights headers:

1. Download the `weights_headers.zip` file from the [GitHub Releases](https://github.com/EmotionEngineer/EmotionLib/releases) page.
2. Extract and place the contents into the respective directories:
   - `filter_weights.c` → `EmotionLib/filter`  
   - `positiveness_weights.c` → `EmotionLib/positiveness`  

#### Building and Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/EmotionEngineer/EmotionLib.git
   ```
2. Refer to **Model Weights Headers** to load the model weights headers.
3. Navigate to the respective directories and run `make` to build each component:
   ```bash
   cd EmotionLib/filter
   make CFLAGS=-fno-lto
   cd ../positiveness
   make CFLAGS=-fno-lto
   cd ../samp
   make
   ```

### Usage

#### Multiple Frames Processing (Video / Image Series)

- C# Import Example for `filter.dll`
  ```csharp
  [DllImport("filter.dll", CallingConvention = CallingConvention.Cdecl)]
  public static extern void filter_VideoInference([In, Out] float[,,,] frames, int num_frames, [In, Out] float[,] results, IntPtr progress);
  ```

- C# Import Example for `positiveness.dll`
  ```csharp
  [DllImport("positiveness.dll", CallingConvention = CallingConvention.Cdecl)]
  public static extern void positiveness_VideoInference([In, Out] float[,,,] frames, int num_frames, [In, Out] float[,] results, IntPtr progress);
  ```

- C# Import Example for `samp.dll`
  ```csharp
  [DllImport("samp.dll", CallingConvention = CallingConvention.Cdecl)]
  public static extern double predictSAMP(string epp_path, string efp_path);
  ```

#### Single Frame Processing (Image)

- `filter_Inference`
  ```csharp
  [DllImport("filter.dll", CallingConvention = CallingConvention.Cdecl)]
  public static extern void filter_Inference([In, Out] float[,,] image, [In, Out] float[] result);
  ```

- `positiveness_Inference`
  ```csharp
  [DllImport("positiveness.dll", CallingConvention = CallingConvention.Cdecl)]
  public static extern void positiveness_Inference([In, Out] float[,,] image, [In, Out] float[] result);
  ```

### Input and Output Guide

#### Frame Processing Overview

- **`filter.dll`**:
  - **Input**: `Nx3x224x224` (batch x channels x height x width).
  - **Output**: Probabilities for:
    - **Safe**
    - **Explicit**
    - **Violent**

- **`positiveness.dll`**:
  - **Input**: `Nx3x227x227` (batch x channels x height x width).
  - **Output**: Probabilities for:
    - **Negativity**
    - **Positivity**

- **`samp.dll`**:
  - **Inputs**: Results from `filter.dll` and `positiveness.dll`.  
  - **Output**:  
    - **`2.0`**: The video is classified as **unsafe** and should be blocked.  
    - **Other values**: The value is interpreted as a **rating**, which maps to an MPAA classification using defined thresholds.  

#### Understanding `filter` Output

The `filter.dll` output is an array of probabilities representing the likelihood that an image falls into one of three content categories:
- **Safe Content**: The probability that the image is free from sensitive material and is safe for viewing.
- **Explicit Material**: The probability that the image contains adult or other explicit content.
- **Violent Content**: The probability that the image contains scenes of violence or brutality.

Each element in the array is a number between **0** and **1**:
- **0** indicates that the image is definitely not classified under the respective category.
- **1** suggests a high likelihood that the image belongs to that category.

#### Understanding `positiveness` Output

The `positiveness.dll` produces probabilities for two distinct classes [**Negativity**, **Positivity**] representing the emotional tone of the content in an image. These probabilities sum to **1** for any given frame and provide a quantitative measure of the emotional context:
- A high probability for **Positivity** indicates predominantly positive emotions.  
- A high probability for **Negativity** suggests the content leans toward negative emotions.

### License

EmotionLib is now released under the **MIT License**, allowing complete freedom for both personal and commercial use. See the `LICENSE` file for details.
