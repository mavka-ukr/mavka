#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <raylib.h>

typedef uint8_t н8;
typedef uint16_t н16;
typedef uint32_t н32;
typedef uint64_t н64;
typedef int8_t ц8;
typedef int16_t ц16;
typedef int32_t ц32;
typedef int64_t ц64;
typedef float р32;
typedef double р64;
typedef uint8_t логічне;
typedef н64 натуральне;
typedef ц64 ціле;
typedef р64 дійсне;
typedef void ніщо;
typedef void* невідома_адреса;
typedef void* невідома_памʼять;

typedef struct ю8 {
  натуральне розмір;
  н8* дані;
} ю8;

static char* ю8_в_cstr(ю8 value) {
  char* copy = (char*)malloc(value.розмір + 1);
  memcpy(copy, value.дані, value.розмір);
  copy[value.розмір] = 0;
  return copy;
}

int deltafontCodepoints[128] = {
  0, /* Кінець */
  1, /* Дія */
  2, /* Початок */
  10, /* Міжряд */
  32, /* Міжслово */
  126, /* Хвиляста */
  38, /* І */
  37, /* Відсоток */
  167, /* Секція */
  35, /* Мітка */
  64, /* Адреса */
  8853, /* Хрестик_в_кругу */
  43, /* Хрестик */
  8372, /* Гривня */
  3, /* Невизначено */
  42, /* Зірочка */
  48, /* Нуль */
  49, /* Один */
  50, /* Два */
  51, /* Три */
  52, /* Чотири */
  53, /* Пʼять */
  54, /* Шість */
  55, /* Сім */
  56, /* Вісім */
  57, /* Девʼять */
  123, /* Відкрита_фігурна_дужка */
  125, /* Закрита_фігурна_дужка */
  91, /* Відкрита_квадратна_дужка */
  93, /* Закрита_квадратна_дужка */
  40, /* Відкрита_дужка */
  41, /* Закрита_дужка */
  60, /* Менше */
  62, /* Більше */
  8743, /* Вище */
  8744, /* Нижче */
  700, /* Твердий */
  39, /* Лапка */
  34, /* Дволапка */
  96, /* Косолапка */
  183, /* Міжкрапка */
  58, /* Двокрапка */
  44, /* Кома */
  59, /* Крапкакома */
  63, /* Питання */
  33, /* Оклик */
  46, /* Крапка */
  47, /* Похила */
  92, /* Обернена_похила */
  124, /* Стояча */
  45, /* Риска */
  172, /* Гачок */
  95, /* Підриска */
  61, /* Двориска */
  1025, /* Велика_буква_Ё */
  1066, /* Велика_буква_Ъ */
  1067, /* Велика_буква_Ы */
  1069, /* Велика_буква_Э */
  1105, /* Мала_буква_ё */
  1098, /* Мала_буква_ъ */
  1099, /* Мала_буква_ы */
  1101, /* Мала_буква_э */
  1168, /* Велика_буква_Ґ */
  1169, /* Мала_буква_ґ */
  1040, /* Велика_буква_А */
  1041, /* Велика_буква_Б */
  1042, /* Велика_буква_В */
  1043, /* Велика_буква_Г */
  1044, /* Велика_буква_Д */
  1045, /* Велика_буква_Е */
  1028, /* Велика_буква_Є */
  1046, /* Велика_буква_Ж */
  1047, /* Велика_буква_З */
  1048, /* Велика_буква_И */
  1030, /* Велика_буква_І */
  1031, /* Велика_буква_Ї */
  1049, /* Велика_буква_Й */
  1050, /* Велика_буква_К */
  1051, /* Велика_буква_Л */
  1052, /* Велика_буква_М */
  1053, /* Велика_буква_Н */
  1054, /* Велика_буква_О */
  1055, /* Велика_буква_П */
  1056, /* Велика_буква_Р */
  1057, /* Велика_буква_С */
  1058, /* Велика_буква_Т */
  1059, /* Велика_буква_У */
  1060, /* Велика_буква_Ф */
  1061, /* Велика_буква_Х */
  1062, /* Велика_буква_Ц */
  1063, /* Велика_буква_Ч */
  1064, /* Велика_буква_Ш */
  1065, /* Велика_буква_Щ */
  1068, /* Велика_буква_Ь */
  1070, /* Велика_буква_Ю */
  1071, /* Велика_буква_Я */
  1072, /* Мала_буква_а */
  1073, /* Мала_буква_б */
  1074, /* Мала_буква_в */
  1075, /* Мала_буква_г */
  1076, /* Мала_буква_д */
  1077, /* Мала_буква_е */
  1108, /* Мала_буква_є */
  1078, /* Мала_буква_ж */
  1079, /* Мала_буква_з */
  1080, /* Мала_буква_и */
  1110, /* Мала_буква_і */
  1111, /* Мала_буква_ї */
  1081, /* Мала_буква_й */
  1082, /* Мала_буква_к */
  1083, /* Мала_буква_л */
  1084, /* Мала_буква_м */
  1085, /* Мала_буква_н */
  1086, /* Мала_буква_о */
  1087, /* Мала_буква_п */
  1088, /* Мала_буква_р */
  1089, /* Мала_буква_с */
  1090, /* Мала_буква_т */
  1091, /* Мала_буква_у */
  1092, /* Мала_буква_ф */
  1093, /* Мала_буква_х */
  1094, /* Мала_буква_ц */
  1095, /* Мала_буква_ч */
  1096, /* Мала_буква_ш */
  1097, /* Мала_буква_щ */
  1100, /* Мала_буква_ь */
  1102, /* Мала_буква_ю */
  1103, /* Мала_буква_я */
};
static Font deltafont;

extern void мавка_бібліотека_вікно_ініціалізувати(натуральне ширина, натуральне висота, ю8* заголовок, натуральне опції) {
  char* title = ю8_в_cstr(*заголовок);

  SetConfigFlags((int)опції);

  InitWindow((int)ширина, (int)висота, title);

  SetExitKey(0);

  free(title);
  
  deltafont = LoadFontEx(
  "/home/kohutd/Downloads/unnamedfont (1).ttf",
  8,
  deltafontCodepoints, 
  128
  );
}

extern void мавка_бібліотека_вікно_закрити() {
  UnloadFont(deltafont);

  CloseWindow();
}

extern bool мавка_бібліотека_вікно_має_закритись() {
  return WindowShouldClose();
}

extern bool мавка_бібліотека_вікно_готове() {
  return IsWindowReady();
}

extern bool мавка_бібліотека_вікно_повноекранне() {
  return IsWindowFullscreen();
}

extern bool мавка_бібліотека_вікно_приховане() {
  return IsWindowHidden();
}

extern bool мавка_бібліотека_вікно_мінімізоване() {
  return IsWindowMinimized();
}

extern bool мавка_бібліотека_вікно_максимізоване() {
  return IsWindowMaximized();
}

extern bool мавка_бібліотека_вікно_сфокусоване() {
  return IsWindowFocused();
}

extern bool мавка_бібліотека_вікно_змінено_розмір() {
  return IsWindowResized();
}

extern bool мавка_бібліотека_вікно_має_опції(натуральне опції) {
  return IsWindowState(опції);
}

extern void мавка_бібліотека_вікно_встановити_опції(натуральне опції) {
  SetWindowState(опції);
}

extern void мавка_бібліотека_вікно_очистити_опції(натуральне опції) {
  ClearWindowState(опції);
}

extern void мавка_бібліотека_вікно_перемкнути_повноекранний_режим() {
  ToggleFullscreen();
}

extern void мавка_бібліотека_вікно_перемкнути_безрамковий_режим() {
  ToggleBorderlessWindowed();
}

extern void мавка_бібліотека_вікно_максимізувати() {
  MaximizeWindow();
}

extern void мавка_бібліотека_вікно_мінімізувати() {
  MinimizeWindow();
}

extern void мавка_бібліотека_вікно_відновити() {
  RestoreWindow();
}

extern void мавка_бібліотека_вікно_встановити_іконку(Image* картинки) {
  SetWindowIcon(*картинки);
}

extern void мавка_бібліотека_вікно_встановити_іконки(Image** картинки, натуральне кількість) {
  SetWindowIcons(*картинки, кількість);
}

extern void мавка_бібліотека_вікно_встановити_заголовок(ю8* заголовок) {
  SetWindowTitle("hello");
}

extern void мавка_бібліотека_вікно_встановити_позицію(натуральне ікс, натуральне ігр) {
  SetWindowPosition((int)ікс, (int)ігр);
}

extern void мавка_бібліотека_вікно_встановити_монітор(натуральне монітор) {
  SetWindowMonitor((int)монітор);
}

extern void мавка_бібліотека_вікно_встановити_мінімальний_розмір(натуральне ширина, натуральне висота) {
  SetWindowMinSize((int)ширина, (int)висота);
}

extern void мавка_бібліотека_вікно_встановити_максимальний_розмір(натуральне ширина, натуральне висота) {
  SetWindowMaxSize((int)ширина, (int)висота);
}

extern void мавка_бібліотека_вікно_встановити_розмір(натуральне ширина, натуральне висота) {
  SetWindowSize((int)ширина, (int)висота);
}

extern void мавка_бібліотека_вікно_встановити_прозорість(р64 прозорість) {
  SetWindowOpacity((float)прозорість);
}

extern void мавка_бібліотека_вікно_встановити_фокус() {
  SetWindowFocused();
}

extern натуральне мавка_бібліотека_вікно_ширина() {
  return (натуральне)GetScreenWidth();
}

extern натуральне мавка_бібліотека_вікно_висота() {
  return (натуральне)GetScreenHeight();
}

extern натуральне мавка_бібліотека_вікно_ширина_рендеру() {
  return (натуральне)GetRenderWidth();
}

extern натуральне мавка_бібліотека_вікно_висота_рендеру() {
  return (натуральне)GetRenderHeight();
}

extern натуральне мавка_бібліотека_вікно_кількість_моніторів() {
  return (натуральне)GetMonitorCount();
}

extern натуральне мавка_бібліотека_вікно_поточний_монітор() {
  return (натуральне)GetMonitorCount();
}

    // Vector2 GetMonitorPosition(int monitor);                    // Get specified monitor position
    // int GetMonitorWidth(int monitor);                           // Get specified monitor width (current video mode used by monitor)
    // int GetMonitorHeight(int monitor);                          // Get specified monitor height (current video mode used by monitor)
    // int GetMonitorPhysicalWidth(int monitor);                   // Get specified monitor physical width in millimetres
    // int GetMonitorPhysicalHeight(int monitor);                  // Get specified monitor physical height in millimetres
    // int GetMonitorRefreshRate(int monitor);                     // Get specified monitor refresh rate
    // Vector2 GetWindowPosition(void);                            // Get window position XY on monitor
    // Vector2 GetWindowScaleDPI(void);                            // Get window scale DPI factor
    // const char *GetMonitorName(int monitor);                    // Get the human-readable, UTF-8 encoded name of the specified monitor
    // void SetClipboardText(const char *text);                    // Set clipboard text content
    // const char *GetClipboardText(void);                         // Get clipboard text content
    // Image GetClipboardImage(void);                              // Get clipboard image
    // void EnableEventWaiting(void);                              // Enable waiting for events on EndDrawing(), no automatic event polling
    // void DisableEventWaiting(void);                             // Disable waiting for events on EndDrawing(), automatic events polling

    // // Cursor-related functions
    // void ShowCursor(void);                                      // Shows cursor
    // void HideCursor(void);                                      // Hides cursor
    // bool IsCursorHidden(void);                                  // Check if cursor is not visible
    // void EnableCursor(void);                                    // Enables cursor (unlock cursor)
    // void DisableCursor(void);                                   // Disables cursor (lock cursor)
    // bool IsCursorOnScreen(void);                                // Check if cursor is on the screen

    // // Drawing-related functions
    // void ClearBackground(Color color);                          // Set background color (framebuffer clear color)
    // void BeginDrawing(void);                                    // Setup canvas (framebuffer) to start drawing
    // void EndDrawing(void);                                      // End canvas drawing and swap buffers (double buffering)
    // void BeginMode2D(Camera2D camera);                          // Begin 2D mode with custom camera (2D)
    // void EndMode2D(void);                                       // Ends 2D mode with custom camera
    // void BeginMode3D(Camera3D camera);                          // Begin 3D mode with custom camera (3D)
    // void EndMode3D(void);                                       // Ends 3D mode and returns to default 2D orthographic mode
    // void BeginTextureMode(RenderTexture2D target);              // Begin drawing to render texture
    // void EndTextureMode(void);                                  // Ends drawing to render texture
    // void BeginShaderMode(Shader shader);                        // Begin custom shader drawing
    // void EndShaderMode(void);                                   // End custom shader drawing (use default shader)
    // void BeginBlendMode(int mode);                              // Begin blending mode (alpha, additive, multiplied, subtract, custom)
    // void EndBlendMode(void);                                    // End blending mode (reset to default: alpha blending)
    // void BeginScissorMode(int x, int y, int width, int height); // Begin scissor mode (define screen area for following drawing)
    // void EndScissorMode(void);                                  // End scissor mode
    // void BeginVrStereoMode(VrStereoConfig config);              // Begin stereo rendering (requires VR simulator)
    // void EndVrStereoMode(void);                                 // End stereo rendering (requires VR simulator)

    // // VR stereo config functions for VR simulator
    // VrStereoConfig LoadVrStereoConfig(VrDeviceInfo device);     // Load VR stereo config for VR simulator device parameters
    // void UnloadVrStereoConfig(VrStereoConfig config);           // Unload VR stereo config

    // // Shader management functions
    // // NOTE: Shader functionality is not available on OpenGL 1.1
    // Shader LoadShader(const char *vsFileName, const char *fsFileName);   // Load shader from files and bind default locations
    // Shader LoadShaderFromMemory(const char *vsCode, const char *fsCode); // Load shader from code strings and bind default locations
    // bool IsShaderValid(Shader shader);                                   // Check if a shader is valid (loaded on GPU)
    // int GetShaderLocation(Shader shader, const char *uniformName);       // Get shader uniform location
    // int GetShaderLocationAttrib(Shader shader, const char *attribName);  // Get shader attribute location
    // void SetShaderValue(Shader shader, int locIndex, const void *value, int uniformType);               // Set shader uniform value
    // void SetShaderValueV(Shader shader, int locIndex, const void *value, int uniformType, int count);   // Set shader uniform value vector
    // void SetShaderValueMatrix(Shader shader, int locIndex, Matrix mat);         // Set shader uniform value (matrix 4x4)
    // void SetShaderValueTexture(Shader shader, int locIndex, Texture2D texture); // Set shader uniform value for texture (sampler2d)
    // void UnloadShader(Shader shader);                                    // Unload shader from GPU memory (VRAM)

    // // Screen-space-related functions
    // #define GetMouseRay GetScreenToWorldRay     // Compatibility hack for previous raylib versions
    // Ray GetScreenToWorldRay(Vector2 position, Camera camera);         // Get a ray trace from screen position (i.e mouse)
    // Ray GetScreenToWorldRayEx(Vector2 position, Camera camera, int width, int height); // Get a ray trace from screen position (i.e mouse) in a viewport
    // Vector2 GetWorldToScreen(Vector3 position, Camera camera);        // Get the screen space position for a 3d world space position
    // Vector2 GetWorldToScreenEx(Vector3 position, Camera camera, int width, int height); // Get size position for a 3d world space position
    // Vector2 GetWorldToScreen2D(Vector2 position, Camera2D camera);    // Get the screen space position for a 2d camera world space position
    // Vector2 GetScreenToWorld2D(Vector2 position, Camera2D camera);    // Get the world space position for a 2d camera screen space position
    // Matrix GetCameraMatrix(Camera camera);                            // Get camera transform matrix (view matrix)
    // Matrix GetCameraMatrix2D(Camera2D camera);                        // Get camera 2d transform matrix

    // // Timing-related functions
    // void SetTargetFPS(int fps);                                 // Set target FPS (maximum)
    // float GetFrameTime(void);                                   // Get time in seconds for last frame drawn (delta time)
    // double GetTime(void);                                       // Get elapsed time in seconds since InitWindow()
    // int GetFPS(void);                                           // Get current FPS

    // // Custom frame control functions
    // // NOTE: Those functions are intended for advanced users that want full control over the frame processing
    // // By default EndDrawing() does this job: draws everything + SwapScreenBuffer() + manage frame timing + PollInputEvents()
    // // To avoid that behaviour and control frame processes manually, enable in config.h: SUPPORT_CUSTOM_FRAME_CONTROL
    // void SwapScreenBuffer(void);                                // Swap back buffer with front buffer (screen drawing)
    // void PollInputEvents(void);                                 // Register all input events
    // void WaitTime(double seconds);                              // Wait for some time (halt program execution)

    // // Random values generation functions
    // void SetRandomSeed(unsigned int seed);                      // Set the seed for the random number generator
    // int GetRandomValue(int min, int max);                       // Get a random value between min and max (both included)
    // int *LoadRandomSequence(unsigned int count, int min, int max); // Load random values sequence, no values repeated
    // void UnloadRandomSequence(int *sequence);                   // Unload random values sequence

    // // Misc. functions
    // void TakeScreenshot(const char *fileName);                  // Takes a screenshot of current screen (filename extension defines format)
    // void SetConfigFlags(unsigned int flags);                    // Setup init configuration flags (view FLAGS)
    // void OpenURL(const char *url);                              // Open URL with default system browser (if available)

    // // NOTE: Following functions implemented in module [utils]
    // //------------------------------------------------------------------
    // void TraceLog(int logLevel, const char *text, ...);         // Show trace log messages (LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR...)
    // void SetTraceLogLevel(int logLevel);                        // Set the current threshold (minimum) log level
    // void *MemAlloc(unsigned int size);                          // Internal memory allocator
    // void *MemRealloc(void *ptr, unsigned int size);             // Internal memory reallocator
    // void MemFree(void *ptr);                                    // Internal memory free

    // // Set custom callbacks
    // // WARNING: Callbacks setup is intended for advanced users
    // void SetTraceLogCallback(TraceLogCallback callback);         // Set custom trace log
    // void SetLoadFileDataCallback(LoadFileDataCallback callback); // Set custom file binary data loader
    // void SetSaveFileDataCallback(SaveFileDataCallback callback); // Set custom file binary data saver
    // void SetLoadFileTextCallback(LoadFileTextCallback callback); // Set custom file text data loader
    // void SetSaveFileTextCallback(SaveFileTextCallback callback); // Set custom file text data saver

    // // Files management functions
    // unsigned char *LoadFileData(const char *fileName, int *dataSize); // Load file data as byte array (read)
    // void UnloadFileData(unsigned char *data);                   // Unload file data allocated by LoadFileData()
    // bool SaveFileData(const char *fileName, void *data, int dataSize); // Save data to file from byte array (write), returns true on success
    // bool ExportDataAsCode(const unsigned char *data, int dataSize, const char *fileName); // Export data to code (.h), returns true on success
    // char *LoadFileText(const char *fileName);                   // Load text data from file (read), returns a '\0' terminated string
    // void UnloadFileText(char *text);                            // Unload file text data allocated by LoadFileText()
    // bool SaveFileText(const char *fileName, char *text);        // Save text data to file (write), string must be '\0' terminated, returns true on success
    // //------------------------------------------------------------------

    // // File system functions
    // bool FileExists(const char *fileName);                      // Check if file exists
    // bool DirectoryExists(const char *dirPath);                  // Check if a directory path exists
    // bool IsFileExtension(const char *fileName, const char *ext); // Check file extension (including point: .png, .wav)
    // int GetFileLength(const char *fileName);                    // Get file length in bytes (NOTE: GetFileSize() conflicts with windows.h)
    // const char *GetFileExtension(const char *fileName);         // Get pointer to extension for a filename string (includes dot: '.png')
    // const char *GetFileName(const char *filePath);              // Get pointer to filename for a path string
    // const char *GetFileNameWithoutExt(const char *filePath);    // Get filename string without extension (uses static string)
    // const char *GetDirectoryPath(const char *filePath);         // Get full path for a given fileName with path (uses static string)
    // const char *GetPrevDirectoryPath(const char *dirPath);      // Get previous directory path for a given path (uses static string)
    // const char *GetWorkingDirectory(void);                      // Get current working directory (uses static string)
    // const char *GetApplicationDirectory(void);                  // Get the directory of the running application (uses static string)
    // int MakeDirectory(const char *dirPath);                     // Create directories (including full path requested), returns 0 on success
    // bool ChangeDirectory(const char *dir);                      // Change working directory, return true on success
    // bool IsPathFile(const char *path);                          // Check if a given path is a file or a directory
    // bool IsFileNameValid(const char *fileName);                 // Check if fileName is valid for the platform/OS
    // FilePathList LoadDirectoryFiles(const char *dirPath);       // Load directory filepaths
    // FilePathList LoadDirectoryFilesEx(const char *basePath, const char *filter, bool scanSubdirs); // Load directory filepaths with extension filtering and recursive directory scan. Use 'DIR' in the filter string to include directories in the result
    // void UnloadDirectoryFiles(FilePathList files);              // Unload filepaths
    // bool IsFileDropped(void);                                   // Check if a file has been dropped into window
    // FilePathList LoadDroppedFiles(void);                        // Load dropped filepaths
    // void UnloadDroppedFiles(FilePathList files);                // Unload dropped filepaths
    // long GetFileModTime(const char *fileName);                  // Get file modification time (last write time)

    // // Compression/Encoding functionality
    // unsigned char *CompressData(const unsigned char *data, int dataSize, int *compDataSize);        // Compress data (DEFLATE algorithm), memory must be MemFree()
    // unsigned char *DecompressData(const unsigned char *compData, int compDataSize, int *dataSize);  // Decompress data (DEFLATE algorithm), memory must be MemFree()
    // char *EncodeDataBase64(const unsigned char *data, int dataSize, int *outputSize);               // Encode data to Base64 string, memory must be MemFree()
    // unsigned char *DecodeDataBase64(const unsigned char *data, int *outputSize);                    // Decode Base64 string data, memory must be MemFree()
    // unsigned int ComputeCRC32(unsigned char *data, int dataSize);     // Compute CRC32 hash code
    // unsigned int *ComputeMD5(unsigned char *data, int dataSize);      // Compute MD5 hash code, returns static int[4] (16 bytes)
    // unsigned int *ComputeSHA1(unsigned char *data, int dataSize);      // Compute SHA1 hash code, returns static int[5] (20 bytes)


    // // Automation events functionality
    // AutomationEventList LoadAutomationEventList(const char *fileName);                // Load automation events list from file, NULL for empty list, capacity = MAX_AUTOMATION_EVENTS
    // void UnloadAutomationEventList(AutomationEventList list);                         // Unload automation events list from file
    // bool ExportAutomationEventList(AutomationEventList list, const char *fileName);   // Export automation events list as text file
    // void SetAutomationEventList(AutomationEventList *list);                           // Set automation event list to record to
    // void SetAutomationEventBaseFrame(int frame);                                      // Set automation event internal base frame to start recording
    // void StartAutomationEventRecording(void);                                         // Start recording automation events (AutomationEventList must be set)
    // void StopAutomationEventRecording(void);                                          // Stop recording automation events
    // void PlayAutomationEvent(AutomationEvent event);                                  // Play a recorded automation event

    // //------------------------------------------------------------------------------------
    // // Input Handling Functions (Module: core)
    // //------------------------------------------------------------------------------------

    // // Input-related functions: keyboard
    // bool IsKeyPressed(int key);                             // Check if a key has been pressed once
    // bool IsKeyPressedRepeat(int key);                       // Check if a key has been pressed again
    // bool IsKeyDown(int key);                                // Check if a key is being pressed
    // bool IsKeyReleased(int key);                            // Check if a key has been released once
    // bool IsKeyUp(int key);                                  // Check if a key is NOT being pressed
    // int GetKeyPressed(void);                                // Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
    // int GetCharPressed(void);                               // Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty
    // void SetExitKey(int key);                               // Set a custom key to exit program (default is ESC)

    // // Input-related functions: gamepads
    // bool IsGamepadAvailable(int gamepad);                                        // Check if a gamepad is available
    // const char *GetGamepadName(int gamepad);                                     // Get gamepad internal name id
    // bool IsGamepadButtonPressed(int gamepad, int button);                        // Check if a gamepad button has been pressed once
    // bool IsGamepadButtonDown(int gamepad, int button);                           // Check if a gamepad button is being pressed
    // bool IsGamepadButtonReleased(int gamepad, int button);                       // Check if a gamepad button has been released once
    // bool IsGamepadButtonUp(int gamepad, int button);                             // Check if a gamepad button is NOT being pressed
    // int GetGamepadButtonPressed(void);                                           // Get the last gamepad button pressed
    // int GetGamepadAxisCount(int gamepad);                                        // Get gamepad axis count for a gamepad
    // float GetGamepadAxisMovement(int gamepad, int axis);                         // Get axis movement value for a gamepad axis
    // int SetGamepadMappings(const char *mappings);                                // Set internal gamepad mappings (SDL_GameControllerDB)
    // void SetGamepadVibration(int gamepad, float leftMotor, float rightMotor, float duration); // Set gamepad vibration for both motors (duration in seconds)

    // // Input-related functions: mouse
    // bool IsMouseButtonPressed(int button);                  // Check if a mouse button has been pressed once
    // bool IsMouseButtonDown(int button);                     // Check if a mouse button is being pressed
    // bool IsMouseButtonReleased(int button);                 // Check if a mouse button has been released once
    // bool IsMouseButtonUp(int button);                       // Check if a mouse button is NOT being pressed
    // int GetMouseX(void);                                    // Get mouse position X
    // int GetMouseY(void);                                    // Get mouse position Y
    // Vector2 GetMousePosition(void);                         // Get mouse position XY
    // Vector2 GetMouseDelta(void);                            // Get mouse delta between frames
    // void SetMousePosition(int x, int y);                    // Set mouse position XY
    // void SetMouseOffset(int offsetX, int offsetY);          // Set mouse offset
    // void SetMouseScale(float scaleX, float scaleY);         // Set mouse scaling
    // float GetMouseWheelMove(void);                          // Get mouse wheel movement for X or Y, whichever is larger
    // Vector2 GetMouseWheelMoveV(void);                       // Get mouse wheel movement for both X and Y
    // void SetMouseCursor(int cursor);                        // Set mouse cursor

    // // Input-related functions: touch
    // int GetTouchX(void);                                    // Get touch position X for touch point 0 (relative to screen size)
    // int GetTouchY(void);                                    // Get touch position Y for touch point 0 (relative to screen size)
    // Vector2 GetTouchPosition(int index);                    // Get touch position XY for a touch point index (relative to screen size)
    // int GetTouchPointId(int index);                         // Get touch point identifier for given index
    // int GetTouchPointCount(void);                           // Get number of touch points

    // //------------------------------------------------------------------------------------
    // // Gestures and Touch Handling Functions (Module: rgestures)
    // //------------------------------------------------------------------------------------
    // void SetGesturesEnabled(unsigned int flags);      // Enable a set of gestures using flags
    // bool IsGestureDetected(unsigned int gesture);     // Check if a gesture have been detected
    // int GetGestureDetected(void);                     // Get latest detected gesture
    // float GetGestureHoldDuration(void);               // Get gesture hold time in seconds
    // Vector2 GetGestureDragVector(void);               // Get gesture drag vector
    // float GetGestureDragAngle(void);                  // Get gesture drag angle
    // Vector2 GetGesturePinchVector(void);              // Get gesture pinch delta
    // float GetGesturePinchAngle(void);                 // Get gesture pinch angle

    // //------------------------------------------------------------------------------------
    // // Camera System Functions (Module: rcamera)
    // //------------------------------------------------------------------------------------
    // void UpdateCamera(Camera *camera, int mode);      // Update camera position for selected mode
    // void UpdateCameraPro(Camera *camera, Vector3 movement, Vector3 rotation, float zoom); // Update camera movement/rotation


typedef struct Вектор2 {
  р64 ікс;
  р64 ігр;
} Вектор2;

extern void мавка_бібліотека_вікно_позиція_монітору(натуральне монітор, Вектор2* вихід) {
  Vector2 v = GetMonitorPosition((int)монітор);
  *вихід = (Вектор2) {
    v.x,
    v.y
  };
}

extern натуральне мавка_бібліотека_вікно_ширина_монітору(натуральне монітор) {
  return (натуральне)GetMonitorWidth(монітор);
}

extern натуральне мавка_бібліотека_вікно_висота_монітору(натуральне монітор) {
  return (натуральне)GetMonitorHeight(монітор);
}

extern натуральне мавка_бібліотека_вікно_фізична_ширина_монітору(натуральне монітор) {
  return (натуральне)GetMonitorPhysicalWidth(монітор);
}

extern натуральне мавка_бібліотека_вікно_фізична_висота_монітору(натуральне монітор) {
  return (натуральне)GetMonitorPhysicalHeight(монітор);
}

extern натуральне мавка_бібліотека_вікно_частота_оновлення_монітору(натуральне монітор) {
  return (натуральне)GetMonitorRefreshRate(монітор);
}

extern void мавка_бібліотека_вікно_позиція(Вектор2* вихід) {
  Vector2 v = GetWindowPosition();
  *вихід = (Вектор2) {
    v.x,
    v.y
  };
}

extern void мавка_бібліотека_вікно_скале_дпі(Вектор2* вихід) {
  Vector2 v = GetWindowScaleDPI();
  *вихід = (Вектор2) {
    v.x,
    v.y
  };
}

extern void мавка_бібліотека_вікно_встановити_текст_буфера_обміну(ю8* значення) {
  char* value = ю8_в_cstr(*значення);
  SetClipboardText(value);
  free(value);
}

extern void мавка_бібліотека_вікно_показати_курсор() {
  ShowCursor();
}

extern void мавка_бібліотека_вікно_приховати_курсор() {
  HideCursor();
}

extern bool мавка_бібліотека_вікно_курсор_приховано() {
  return IsCursorHidden();
}

extern void мавка_бібліотека_вікно_увімкнути_курсор() {
  EnableCursor();
}

extern void мавка_бібліотека_вікно_вимкнути_курсор() {
  DisableCursor();
}

extern bool мавка_бібліотека_вікно_курсор_на_екрані() {
  return IsCursorOnScreen();
}

extern void мавка_бібліотека_вікно_очистити_фон(н8 ч, н8 з, н8 с, н8 п) {
  ClearBackground((Color) { ч, з, с, п });
}

extern void мавка_бібліотека_вікно_почати_малювання() {
  BeginDrawing();
}

extern void мавка_бібліотека_вікно_закінчити_малювання() {
  EndDrawing();
}

extern void мавка_бібліотека_вікно_встановити_бажану_ккс(натуральне значення) {
  SetTargetFPS((int)значення);
}

extern void мавка_бібліотека_вікно_написати(ю8* значення, натуральне ікс, натуральне ігр, р64 розмір, р64 відступ, н8 ч, н8 з, н8 с, н8 п, Font* шрифт) {
  Font font;
  if (шрифт == NULL) {
    font = deltafont;
  } else {
    font = *шрифт;
  }
  char* value = ю8_в_cstr(*значення);
  DrawTextEx(
    font, 
    value,
    (Vector2) { ікс, ігр }, 
    (float)розмір, 
    (float)відступ, 
    (Color) { ч, з, с, п }
  );
  free(value);
}

extern натуральне мавка_бібліотека_вікно_ікс_миші() {
  return (натуральне)GetMouseX();
}

extern натуральне мавка_бібліотека_вікно_ігр_миші() {
  return (натуральне)GetMouseY();
}

extern р64 мавка_бібліотека_вікно_рух_колеса_миші() {
  return (р64)GetMouseWheelMove();
}

extern натуральне мавка_бібліотека_вікно_натиснутий_символ_юнікоду() {
  return (натуральне)GetCharPressed();
}

extern натуральне мавка_бібліотека_вікно_натиснута_клавіша() {
  return (натуральне)GetKeyPressed();
}

extern bool мавка_бібліотека_вікно_клавішу_затиснуто(натуральне клавіша) {
  return IsKeyDown((int)клавіша);
}