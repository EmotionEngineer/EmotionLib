# EmotionLib
## Simple Dynamic Library for Video Sentiment Recognition

![Demo 1](https://raw.githubusercontent.com/EmotionEngineer/EmotionLib/master/Demo/1.png) ![Demo 2](https://raw.githubusercontent.com/EmotionEngineer/EmotionLib/master/Demo/2.png)

**EmotionLib** is a dynamic library designed for video sentiment recognition, written entirely in pure C. This library allows you to analyze the emotions expressed in a sequence of video frames. Please note that it is currently in the BETA stage and supports only single-threaded operation.

## Features

- Analyze video sentiment based on a sequence of frames
- Provides a C# import example for easy integration
- Progress tracking for recognition
- Pure C implementation

## Functionality

### `void videoSentiment(const float frames[][3][224][224], int num_frames, float tensor_predictions[][4], int* progress)`

- `frames`: A tensor-array containing video frames.
- `num_frames`: The number of frames in the video.
- `tensor_predictions`: Output for the sentiment predictions.
- `progress`: An integer pointer to track recognition progress.

## Usage in C#

Here is an example of how to import the EmotionLib in C#:

```csharp
[DllImport("emotionLib.dll", CallingConvention = CallingConvention.Cdecl)]
public static extern void videoSentiment([In, Out] float[,,,] frames, int num_frames, [In, Out] float[,] tensor_predictions, IntPtr progress);
```

## TODO

- Multithreading support
