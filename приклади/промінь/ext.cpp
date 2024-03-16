#include "iostream"
#include "mavka_api_v0.h"
#include "raylib-5.0_linux_amd64/include/raylib.h"

using namespace mavka::api::v0;

extern "C" MavkaValue мавка_розширити(Mavka* mavka) {
  const auto prominModuleObject = mavka->createObject(mavka);

  const auto InitWindowDiiaObject = mavka->createDiia(
      mavka, "ініціалізувати_вікно",
      [](Mavka* mavka, MavkaPointer diiaObject, MavkaPointer args, size_t li) {
        const auto width = mavka->getArg(mavka, args, 0, "ширина");
        const auto height = mavka->getArg(mavka, args, 1, "висота");
        const auto title = mavka->getArg(mavka, args, 2, "заголовок");
        InitWindow(width.data.number, height.data.number,
                   mavka->getTextData(mavka, title.data.object));
        return MavkaValue{MavkaValueTypeEmpty, {}};
      });
  mavka->set(
      mavka, prominModuleObject, "ініціалізувати_вікно",
      MavkaValue{MavkaValueTypeObject, {.object = InitWindowDiiaObject}});

  const auto WindowShouldCloseDiiaObject = mavka->createDiia(
      mavka, "вікно_показується",
      [](Mavka* mavka, MavkaPointer diiaObject, MavkaPointer args, size_t li) {
        if (!WindowShouldClose()) {
          return MavkaValue{MavkaValueTypeYes, {}};
        } else {
          return MavkaValue{MavkaValueTypeNo, {}};
        }
      });
  mavka->set(mavka, prominModuleObject, "вікно_показується",
             MavkaValue{MavkaValueTypeObject,
                        {.object = WindowShouldCloseDiiaObject}});

  const auto CloseWindowDiiaObject = mavka->createDiia(
      mavka, "закрити_вікно",
      [](Mavka* mavka, MavkaPointer diiaObject, MavkaPointer args, size_t li) {
        CloseWindow();
        return MavkaValue{MavkaValueTypeEmpty, {}};
      });
  mavka->set(
      mavka, prominModuleObject, "закрити_вікно",
      MavkaValue{MavkaValueTypeObject, {.object = CloseWindowDiiaObject}});

  const auto BeginDrawingDiiaObject = mavka->createDiia(
      mavka, "почати_малювання",
      [](Mavka* mavka, MavkaPointer diiaObject, MavkaPointer args, size_t li) {
        BeginDrawing();
        return MavkaValue{MavkaValueTypeEmpty, {}};
      });
  mavka->set(
      mavka, prominModuleObject, "почати_малювання",
      MavkaValue{MavkaValueTypeObject, {.object = BeginDrawingDiiaObject}});

  const auto EndDrawingDiiaObject = mavka->createDiia(
      mavka, "закінчити_малювання",
      [](Mavka* mavka, MavkaPointer diiaObject, MavkaPointer args, size_t li) {
        EndDrawing();
        return MavkaValue{MavkaValueTypeEmpty, {}};
      });
  mavka->set(
      mavka, prominModuleObject, "закінчити_малювання",
      MavkaValue{MavkaValueTypeObject, {.object = EndDrawingDiiaObject}});

  const auto ClearBackgroundDiiaObject = mavka->createDiia(
      mavka, "очистити_фон",
      [](Mavka* mavka, MavkaPointer diiaObject, MavkaPointer args, size_t li) {
        const auto color = mavka->getArg(mavka, args, 0, "колір");
        const auto r = mavka->get(mavka, color.data.object, "ч");
        const auto g = mavka->get(mavka, color.data.object, "з");
        const auto b = mavka->get(mavka, color.data.object, "с");
        const auto a = mavka->get(mavka, color.data.object, "п");
        ClearBackground({static_cast<unsigned char>(r.data.number),
                         static_cast<unsigned char>(g.data.number),
                         static_cast<unsigned char>(b.data.number),
                         static_cast<unsigned char>(a.data.number)});
        return MavkaValue{MavkaValueTypeEmpty, {}};
      });
  mavka->set(
      mavka, prominModuleObject, "очистити_фон",
      MavkaValue{MavkaValueTypeObject, {.object = ClearBackgroundDiiaObject}});

  const auto DrawTextDiiaObject = mavka->createDiia(
      mavka, "намалювати_текст",
      [](Mavka* mavka, MavkaPointer diiaObject, MavkaPointer args, size_t li) {
        const auto text = mavka->getArg(mavka, args, 0, "т");
        const auto x = mavka->getArg(mavka, args, 1, "х");
        const auto y = mavka->getArg(mavka, args, 2, "у");
        const auto size = mavka->getArg(mavka, args, 3, "розмір");
        const auto color = mavka->getArg(mavka, args, 4, "колір");
        const auto r = mavka->get(mavka, color.data.object, "ч");
        const auto g = mavka->get(mavka, color.data.object, "з");
        const auto b = mavka->get(mavka, color.data.object, "с");
        const auto a = mavka->get(mavka, color.data.object, "п");
        DrawText(mavka->getTextData(mavka, text.data.object), x.data.number,
                 y.data.number, size.data.number,
                 {static_cast<unsigned char>(r.data.number),
                  static_cast<unsigned char>(g.data.number),
                  static_cast<unsigned char>(b.data.number),
                  static_cast<unsigned char>(a.data.number)});
        return MavkaValue{MavkaValueTypeEmpty, {}};
      });
  mavka->set(mavka, prominModuleObject, "намалювати_текст",
             MavkaValue{MavkaValueTypeObject, {.object = DrawTextDiiaObject}});

  return MavkaValue{MavkaValueTypeObject, {.object = prominModuleObject}};
}