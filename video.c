#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
    long long movie_frames = (long long)durationMovie * fps;
    long long credits_frames = (long long)durationCredits * fps;
    long long colorFrameSize = (long long)w*h*3;
    long long bwFrameSize = (long long)w*h*1;
    long long totalBytesLL =movie_frames*colorFrameSize +credits_frames*bwFrameSize;
    float totalBytes = (float) totalBytesLL;
    if (strcmp(unit, "bt") == 0) {
        return totalBytes;
    } else if (strcmp(unit, "ko") == 0) {
        return totalBytes / 1024.0f;
    } else if (strcmp(unit, "mo") == 0) {
        return totalBytes / (1024.0f * 1024.0f);
    } else if (strcmp(unit, "go") == 0) {
        return totalBytes / (1024.0f * 1024.0f * 1024.0f);
    }
   return totalBytes;
}
