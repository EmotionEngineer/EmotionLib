# EmotionLib
## Simple dynamic library for video sentiment recognition
### Made using Caffe  
### Functions list:  
__- float* make(const char* path, double N, struct progress* bar)__, where **progress** is struct{int,int} to check the current progress of recognition  
_Returns a float array pointer with positivity values for each __N__-th frame of video in **path**, first array element is database size_


You can use N = 0 for automatic frame rate detection. In this case, the function will take one frame for every second of the video  

__- int clean(float* res)__  
_To clean up an array with coefficients_

### C# Import Example:
        [StructLayout(LayoutKind.Sequential)]
        public struct progress
        {
            public int cur;
            public int end;
        };
        [DllImport("EmotionLib.dll")]
        public static extern IntPtr make([MarshalAs(UnmanagedType.LPStr)] string path, double N, ref progress bar);
        [DllImport("EmotionLib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int clean(IntPtr ptr);
### Demo
![alt text](https://raw.githubusercontent.com/EmotionEngineer/EmotionLib/master/Demo/1.png)
![alt text](https://raw.githubusercontent.com/EmotionEngineer/EmotionLib/master/Demo/2.png)
### TODO:
**- Audio sentiment recognition**
