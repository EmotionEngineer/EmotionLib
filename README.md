# EmotionLib
### Advanced Dynamic Library for Video Sentiment and Content Recognition

![Demo 1](https://raw.githubusercontent.com/EmotionEngineer/EmotionLib/master/Demo/1.png)
![Demo 2](https://raw.githubusercontent.com/EmotionEngineer/EmotionLib/master/Demo/2.png)

**EmotionLib** is a comprehensive dynamic library designed for video sentiment recognition and content classification, written entirely in pure C. This powerful library enables developers to accurately analyze emotions and content within video frames. It has progressed beyond its preview stage and now offers enhanced capabilities, including multithreading support for efficient operation.

#### Key Features

- **Sentiment Analysis**: Determine the emotional context from a sequence of video frames.
- **Content Classification**: Classify images for the presence of sensitive content, such as explicit material or violence.
- **C# Integration**: Seamless integration with C# applications, complete with usage examples.
- **Progress Tracking**: Monitor the recognition process with real-time progress updates.
- **Pure C Implementation**: Optimized for performance and compatibility.

#### Components

The library consists of two main components:

- `filter.dll`
  - Handles the classification of images into categories:
    - Safe content
    - Explicit material
    - Violent content

- `positiveness.dll`
  - Assesses the positivity or negativity of frames that do not contain prohibited content but may evoke negative emotions.

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
2. Extract the contents of the zip file, which should include:
   - `filter/filter_weights.c`
   - `positiveness/positiveness_weights.c`
3. Place the extracted files into their respective directories within the cloned repository:
   - The `filter_weights.c` file goes into the `EmotionLib/filter` directory.
   - The `positiveness_weights.c` file goes into the `EmotionLib/positiveness` directory.

#### Building and Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/EmotionEngineer/EmotionLib.git
   ```
2. Refer to **Model Weights Headers** to load the model weights headers.
3. Navigate to the respective directories and run `make` to build each component:
   ```bash
   cd EmotionLib/filter
   make
   cd ../positiveness
   make
   ```

### Usage

#### Multiple Frames Processing

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

#### Single Frame Processing

- `filter_Inference`
  ```csharp
  [DllImport("filter.dll", CallingConvention = CallingConvention.Cdecl)]
  public static extern void filter_Inference([In, Out] float[,,] frame, [In, Out] float[] result);
  ```

- `positiveness_Inference`
  ```csharp
  [DllImport("positiveness.dll", CallingConvention = CallingConvention.Cdecl)]
  public static extern void positiveness_Inference([In, Out] float[,,] frame, [In, Out] float[] result);
  ```

### Input and Output Format Guide

#### Required Input Arrays

##### `filter.dll`:
- **Single Frame Processing**: 
  - Input size: `3x224x224` (channels x height x width)
- **Multiple Frames Processing**: 
  - Input size: `Nx3x224x224` (batch size x channels x height x width)

##### `positiveness.dll`:
- **Single Frame Processing**: 
  - Input size: `3x256x256` (channels x height x width)
- **Multiple Frames Processing**: 
  - Input size: `Nx3x256x256` (batch size x channels x height x width)

#### Understanding the `filter.dll` Output

The `filter.dll` output is an array of probabilities representing the likelihood that an image falls into one of three content categories:
- **Safe Content**: The probability that the image is free from sensitive material and is safe for viewing.
- **Explicit Material**: The probability that the image contains adult or other explicit content.
- **Violent Content**: The probability that the image contains scenes of violence or brutality.

Each element in the array is a number between **0** and **1**:
- **0** indicates that the image is definitely not classified under the respective category.
- **1** suggests a high likelihood that the image belongs to that category.

#### Understanding `positiveness` Output

The `positiveness` output value is a floating-point number ranging from **0** to **1**, representing the positivity of the content within a video frame:
- **0**: Indicates the content is **absolutely positive**, with no negative emotions detected.
- **1**: Represents **absolutely negative** content, suggesting strong negative emotions.

Values between **0** and **1** indicate varying degrees of positivity, with lower numbers closer to **0** being more positive and those approaching **1** being more negative.

### Contributing

Contributions are welcome! If you would like to contribute to EmotionLib, please submit a pull request or open an issue for discussion.

### License

EmotionLib is released under a special license that permits only non-commercial use. For commercial use, please open an issue in the GitHub repository to discuss licensing options.
