; ModuleID = '/home/kohutd/CLionProjects/mavka-1.0.0/./непотріб/розширення_привіт.ц'
source_filename = "/home/kohutd/CLionProjects/mavka-1.0.0/./\D0\BD\D0\B5\D0\BF\D0\BE\D1\82\D1\80\D1\96\D0\B1/\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F_\D0\BF\D1\80\D0\B8\D0\B2\D1\96\D1\82.\D1\86"

%"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F" = type { %"\D0\A0\D0\9C\D0\B21::\D0\92\D0\B5\D1\80\D1\81\D1\96\D1\8F\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr }
%"\D0\A0\D0\9C\D0\B21::\D0\92\D0\B5\D1\80\D1\81\D1\96\D1\8F\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F" = type { i64, i64, i64 }
%"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" = type { ptr, ptr }

@0 = private constant [14 x i8] c"Hello, world!\00"

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BF\D0\B0\D0\B4\D1\96\D0\BD\D0\BD\D1\8F"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load2 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load2, i32 0, i32 3
  %load3 = load ptr, ptr %inst, align 8
  %inst2 = call ptr %load3()
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load1 = load ptr, ptr %return1, align 8
  ret ptr %load1
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82_\D1\83\D1\81\D0\BF\D1\96\D1\85"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %construct = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %construct, i32 0, i32 0
  store ptr null, ptr %inst, align 8
  %inst2 = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %construct, i32 0, i32 1
  %load5 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store ptr %load5, ptr %inst2, align 8
  %load6 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %construct, align 8
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load6, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load4 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load4
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82_\D0\BF\D0\B0\D0\B4\D1\96\D0\BD\D0\BD\D1\8F"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %construct = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %construct, i32 0, i32 0
  %load8 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call ptr @"\D0\A0\D0\9C\D0\B21::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BF\D0\B0\D0\B4\D1\96\D0\BD\D0\BD\D1\8F"(ptr %load8)
  store ptr %inst2, ptr %inst, align 8
  %inst3 = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %construct, i32 0, i32 1
  %load9 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store ptr %load9, ptr %inst3, align 8
  %load10 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %construct, align 8
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load10, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load7 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load7
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D0\BE\D1\82\D1\80\D0\B8\D0\BC\D0\B0\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BC\D0\BE\D0\B4\D1\83\D0\BB\D1\8F_\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load12 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load12, i32 0, i32 4
  %load13 = load ptr, ptr %inst, align 8
  store ptr %load13, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load11 = load ptr, ptr %return1, align 8
  ret ptr %load11
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\B0\D0\BF\D0\B8\D1\81\D0\B0\D1\82\D0\B8_\D0\B4\D0\B0\D0\BD\D1\96_\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F"(ptr %0, ptr %1) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B4\D0\B0\D0\BD\D1\96" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B4\D0\B0\D0\BD\D1\96", align 8
  %load14 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load14, i32 0, i32 1
  %load15 = load ptr, ptr %"\D0\B4\D0\B0\D0\BD\D1\96", align 8
  store ptr %load15, ptr %inst, align 8
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\AE8"(ptr %0, ptr %1) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load16 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load16, i32 0, i32 7
  %load17 = load ptr, ptr %inst, align 8
  %load18 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load19 = load ptr, ptr %"\D0\A0", align 8
  call void %load17(ptr %load18, ptr %load19)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %0, ptr %1, i64 %2) {
alloca:
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B3\D0\BB\D0\B8\D0\B1\D0\B8\D0\BD\D0\B0" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store i64 %2, ptr %"\D0\B3\D0\BB\D0\B8\D0\B1\D0\B8\D0\BD\D0\B0", align 4
  %load20 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load20, i32 0, i32 8
  %load21 = load ptr, ptr %inst, align 8
  %load22 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load23 = load ptr, ptr %"\D0\A0", align 8
  %load24 = load i64, ptr %"\D0\B3\D0\BB\D0\B8\D0\B1\D0\B8\D0\BD\D0\B0", align 4
  call void %load21(ptr %load22, ptr %load23, i64 %load24)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\B2\D0\B7\D1\8F\D1\82\D0\B8_\D1\84\D0\B0\D0\B9\D0\BB"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0_\D0\BC\D0\BE\D0\B4\D1\83\D0\BB\D1\8F" = alloca ptr, align 8
  %"\D1\88\D0\BB\D1\8F\D1\85_\D0\B4\D0\BE_\D1\84\D0\B0\D0\B9\D0\BB\D1\83" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0_\D0\BC\D0\BE\D0\B4\D1\83\D0\BB\D1\8F", align 8
  store ptr %2, ptr %"\D1\88\D0\BB\D1\8F\D1\85_\D0\B4\D0\BE_\D1\84\D0\B0\D0\B9\D0\BB\D1\83", align 8
  %load26 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load26, i32 0, i32 9
  %load27 = load ptr, ptr %inst, align 8
  %load28 = load ptr, ptr %"\D0\A0", align 8
  %load29 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0_\D0\BC\D0\BE\D0\B4\D1\83\D0\BB\D1\8F", align 8
  %load30 = load ptr, ptr %"\D1\88\D0\BB\D1\8F\D1\85_\D0\B4\D0\BE_\D1\84\D0\B0\D0\B9\D0\BB\D1\83", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load27(ptr %load28, ptr %load29, ptr %load30)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load25 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load25
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B3\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %0, ptr %1) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load31 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load31, i32 0, i32 10
  %load32 = load ptr, ptr %inst, align 8
  %load33 = load ptr, ptr %"\D0\A0", align 8
  %load34 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  call void %load32(ptr %load33, ptr %load34)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\B2\D0\B8\D0\B4\D0\B0\D0\BB\D0\B8\D1\82\D0\B8_\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B6\D0\B5\D0\BD\D0\B8\D0\B9_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %0) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load35 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load35, i32 0, i32 11
  %load36 = load ptr, ptr %inst, align 8
  %load37 = load ptr, ptr %"\D0\A0", align 8
  call void %load36(ptr %load37)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0_\D0\B7_\D0\AE8"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load39 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load39, i32 0, i32 12
  %load40 = load ptr, ptr %inst, align 8
  %load41 = load ptr, ptr %"\D0\A0", align 8
  %load42 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr %load40(ptr %load41, ptr %load42)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load38 = load ptr, ptr %return1, align 8
  ret ptr %load38
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D0\BD\D0\B0\D1\82\D0\B8\D0\B2\D0\BD\D1\83_\D0\B4\D1\96\D1\8E"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  store ptr %2, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load44 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load44, i32 0, i32 13
  %load45 = load ptr, ptr %inst, align 8
  %load46 = load ptr, ptr %"\D0\A0", align 8
  %load47 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load48 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr %load45(ptr %load46, ptr %load47, ptr %load48)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load43 = load ptr, ptr %return1, align 8
  ret ptr %load43
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\87\D0\B8\D1\81\D0\BB\D0\BE"(ptr %0, double %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca double, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store double %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load50 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load50, i32 0, i32 14
  %load51 = load ptr, ptr %inst, align 8
  %load52 = load ptr, ptr %"\D0\A0", align 8
  %load53 = load double, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr %load51(ptr %load52, double %load53)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load49 = load ptr, ptr %return1, align 8
  ret ptr %load49
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\82\D0\B5\D0\BA\D1\81\D1\82_\D0\B7_\D0\AE8"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load55 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load55, i32 0, i32 15
  %load56 = load ptr, ptr %inst, align 8
  %load57 = load ptr, ptr %"\D0\A0", align 8
  %load58 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr %load56(ptr %load57, ptr %load58)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load54 = load ptr, ptr %return1, align 8
  ret ptr %load54
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4_\D0\B7_\D0\AE8"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load60 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load60, i32 0, i32 16
  %load61 = load ptr, ptr %inst, align 8
  %load62 = load ptr, ptr %"\D0\A0", align 8
  %load63 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr %load61(ptr %load62, ptr %load63)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load59 = load ptr, ptr %return1, align 8
  ret ptr %load59
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D0\BC\D0\BE\D0\B4\D1\83\D0\BB\D1\8C"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load65 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load65, i32 0, i32 17
  %load66 = load ptr, ptr %inst, align 8
  %load67 = load ptr, ptr %"\D0\A0", align 8
  %load68 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %inst2 = call ptr %load66(ptr %load67, ptr %load68)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load64 = load ptr, ptr %return1, align 8
  ret ptr %load64
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load70 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load70, i32 0, i32 18
  %load71 = load ptr, ptr %inst, align 8
  %load72 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call ptr %load71(ptr %load72)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load69 = load ptr, ptr %return1, align 8
  ret ptr %load69
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\81\D0\BB\D0\BE\D0\B2\D0\BD\D0\B8\D0\BA"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load74 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load74, i32 0, i32 19
  %load75 = load ptr, ptr %inst, align 8
  %load76 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call ptr %load75(ptr %load76)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load73 = load ptr, ptr %return1, align 8
  ret ptr %load73
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load78 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load78, i32 0, i32 20
  %load79 = load ptr, ptr %inst, align 8
  %load80 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call ptr %load79(ptr %load80)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load77 = load ptr, ptr %return1, align 8
  ret ptr %load77
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B2\D0\B8\D0\BA\D0\BE\D0\BD\D0\B0\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %0, ptr %1, i64 %2, ptr %3) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2" = alloca i64, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store i64 %2, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2", align 4
  store ptr %3, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8", align 8
  %load82 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load82, i32 0, i32 21
  %load83 = load ptr, ptr %inst, align 8
  %load84 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load85 = load ptr, ptr %"\D0\A0", align 8
  %load86 = load i64, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2", align 4
  %load87 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load83(ptr %load84, ptr %load85, i64 %load86, ptr %load87)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load81 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load81
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BE\D1\82\D1\80\D0\B8\D0\BC\D0\B0\D1\82\D0\B8_\D0\B2\D0\BB\D0\B0\D1\81\D1\82\D0\B8\D0\B2\D1\96\D1\81\D1\82\D1\8C"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load89 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load89, i32 0, i32 22
  %load90 = load ptr, ptr %inst, align 8
  %load91 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load92 = load ptr, ptr %"\D0\A0", align 8
  %load93 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load90(ptr %load91, ptr %load92, ptr %load93)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load88 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load88
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\BC\D1\96\D0\BD\D0\B8\D1\82\D0\B8_\D0\B2\D0\BB\D0\B0\D1\81\D1\82\D0\B8\D0\B2\D1\96\D1\81\D1\82\D1\8C"(ptr %0, ptr %1, ptr %2, ptr %3) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  store ptr %3, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load95 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load95, i32 0, i32 23
  %load96 = load ptr, ptr %inst, align 8
  %load97 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load98 = load ptr, ptr %"\D0\A0", align 8
  %load99 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load100 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load96(ptr %load97, ptr %load98, ptr %load99, ptr %load100)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load94 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load94
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B2\D0\B8\D0\B4\D0\B0\D0\BB\D0\B8\D1\82\D0\B8_\D0\B2\D0\BB\D0\B0\D1\81\D1\82\D0\B8\D0\B2\D1\96\D1\81\D1\82\D1\8C"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load102 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load102, i32 0, i32 24
  %load103 = load ptr, ptr %inst, align 8
  %load104 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load105 = load ptr, ptr %"\D0\A0", align 8
  %load106 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load103(ptr %load104, ptr %load105, ptr %load106)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load101 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load101
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B2\D0\B8\D0\BA\D0\BE\D0\BD\D0\B0\D1\82\D0\B8_\D0\B2\D0\BB\D0\B0\D1\81\D1\82\D0\B8\D0\B2\D1\96\D1\81\D1\82\D1\8C"(ptr %0, ptr %1, ptr %2, i64 %3, ptr %4) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0" = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2" = alloca i64, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  store i64 %3, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2", align 4
  store ptr %4, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8", align 8
  %load108 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load108, i32 0, i32 25
  %load109 = load ptr, ptr %inst, align 8
  %load110 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load111 = load ptr, ptr %"\D0\A0", align 8
  %load112 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load113 = load i64, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2", align 4
  %load114 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load109(ptr %load110, ptr %load111, ptr %load112, i64 %load113, ptr %load114)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load107 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load107
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BE\D1\82\D1\80\D0\B8\D0\BC\D0\B0\D1\82\D0\B8_\D0\B5\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BA\D0\BB\D1\8E\D1\87" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  %load116 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load116, i32 0, i32 26
  %load117 = load ptr, ptr %inst, align 8
  %load118 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load119 = load ptr, ptr %"\D0\A0", align 8
  %load120 = load ptr, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load117(ptr %load118, ptr %load119, ptr %load120)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load115 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load115
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\BC\D1\96\D0\BD\D0\B8\D1\82\D0\B8_\D0\B5\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82"(ptr %0, ptr %1, ptr %2, ptr %3) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BA\D0\BB\D1\8E\D1\87" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  store ptr %3, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load122 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load122, i32 0, i32 27
  %load123 = load ptr, ptr %inst, align 8
  %load124 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load125 = load ptr, ptr %"\D0\A0", align 8
  %load126 = load ptr, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  %load127 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load123(ptr %load124, ptr %load125, ptr %load126, ptr %load127)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load121 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load121
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B2\D0\B8\D0\B4\D0\B0\D0\BB\D0\B8\D1\82\D0\B8_\D0\B5\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BA\D0\BB\D1\8E\D1\87" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  %load129 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load129, i32 0, i32 28
  %load130 = load ptr, ptr %inst, align 8
  %load131 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load132 = load ptr, ptr %"\D0\A0", align 8
  %load133 = load ptr, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load130(ptr %load131, ptr %load132, ptr %load133)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load128 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load128
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BE\D1\82\D1\80\D0\B8\D0\BC\D0\B0\D1\82\D0\B8_\D0\BF\D0\B5\D1\80\D0\B5\D0\B1\D1\96\D1\80"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load135 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load135, i32 0, i32 29
  %load136 = load ptr, ptr %inst, align 8
  %load137 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load138 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load136(ptr %load137, ptr %load138)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load134 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load134
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load140 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load140, i32 0, i32 30
  %load141 = load ptr, ptr %inst, align 8
  %load142 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load143 = load ptr, ptr %"\D0\A0", align 8
  %load144 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load141(ptr %load142, ptr %load143, ptr %load144)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load139 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load139
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B2\D1\96\D0\B4\D0\BD\D1\8F\D1\82\D0\B8"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load146 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load146, i32 0, i32 31
  %load147 = load ptr, ptr %inst, align 8
  %load148 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load149 = load ptr, ptr %"\D0\A0", align 8
  %load150 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load147(ptr %load148, ptr %load149, ptr %load150)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load145 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load145
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BF\D0\BE\D0\BC\D0\BD\D0\BE\D0\B6\D0\B8\D1\82\D0\B8"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load152 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load152, i32 0, i32 32
  %load153 = load ptr, ptr %inst, align 8
  %load154 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load155 = load ptr, ptr %"\D0\A0", align 8
  %load156 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load153(ptr %load154, ptr %load155, ptr %load156)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load151 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load151
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BF\D0\BE\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load158 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load158, i32 0, i32 33
  %load159 = load ptr, ptr %inst, align 8
  %load160 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load161 = load ptr, ptr %"\D0\A0", align 8
  %load162 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load159(ptr %load160, ptr %load161, ptr %load162)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load157 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load157
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BE\D1\81\D1\82\D0\B0\D1\87\D0\B0"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load164 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load164, i32 0, i32 34
  %load165 = load ptr, ptr %inst, align 8
  %load166 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load167 = load ptr, ptr %"\D0\A0", align 8
  %load168 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load165(ptr %load166, ptr %load167, ptr %load168)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load163 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load163
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BD\D0\B5\D0\BF\D0\BE\D0\B2\D0\BD\D0\B0_\D1\87\D0\B0\D1\81\D1\82\D0\BA\D0\B0"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load170 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load170, i32 0, i32 35
  %load171 = load ptr, ptr %inst, align 8
  %load172 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load173 = load ptr, ptr %"\D0\A0", align 8
  %load174 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load171(ptr %load172, ptr %load173, ptr %load174)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load169 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load169
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D1\82\D0\B5\D0\BF\D1\96\D0\BD\D1\8C"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load176 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load176, i32 0, i32 36
  %load177 = load ptr, ptr %inst, align 8
  %load178 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load179 = load ptr, ptr %"\D0\A0", align 8
  %load180 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load177(ptr %load178, ptr %load179, ptr %load180)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load175 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load175
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B2\D0\BB\D1\96\D0\B2\D0\BE"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load182 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load182, i32 0, i32 37
  %load183 = load ptr, ptr %inst, align 8
  %load184 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load185 = load ptr, ptr %"\D0\A0", align 8
  %load186 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load183(ptr %load184, ptr %load185, ptr %load186)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load181 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load181
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B2\D0\BF\D1\80\D0\B0\D0\B2\D0\BE_\D0\B7\D1\96_\D0\B7\D0\B0\D0\BF\D0\BE\D0\B2\D0\BD\D0\B5\D0\BD\D0\BD\D1\8F\D0\BC"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load188 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load188, i32 0, i32 38
  %load189 = load ptr, ptr %inst, align 8
  %load190 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load191 = load ptr, ptr %"\D0\A0", align 8
  %load192 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load189(ptr %load190, ptr %load191, ptr %load192)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load187 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load187
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B4\D0\B2\D1\96\D0\B9\D0\BA\D0\BE\D0\B2\D0\B5_\D1\96"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load194 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load194, i32 0, i32 39
  %load195 = load ptr, ptr %inst, align 8
  %load196 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load197 = load ptr, ptr %"\D0\A0", align 8
  %load198 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load195(ptr %load196, ptr %load197, ptr %load198)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load193 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load193
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B4\D0\B2\D1\96\D0\B9\D0\BA\D0\BE\D0\B2\D0\B5_\D0\B0\D0\B1\D0\BE"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load200 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load200, i32 0, i32 40
  %load201 = load ptr, ptr %inst, align 8
  %load202 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load203 = load ptr, ptr %"\D0\A0", align 8
  %load204 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load201(ptr %load202, ptr %load203, ptr %load204)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load199 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load199
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B4\D0\B2\D1\96\D0\B9\D0\BA\D0\BE\D0\B2\D0\B5_\D0\B2\D0\B8\D0\BA\D0\BB\D1\8E\D1\87\D0\BD\D0\B5_\D0\B0\D0\B1\D0\BE"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load206 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load206, i32 0, i32 41
  %load207 = load ptr, ptr %inst, align 8
  %load208 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load209 = load ptr, ptr %"\D0\A0", align 8
  %load210 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load207(ptr %load208, ptr %load209, ptr %load210)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load205 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load205
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B4\D0\B2\D1\96\D0\B9\D0\BA\D0\BE\D0\B2\D0\B5_\D0\BD\D0\B5"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load212 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load212, i32 0, i32 42
  %load213 = load ptr, ptr %inst, align 8
  %load214 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load215 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load213(ptr %load214, ptr %load215)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load211 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load211
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B1\D1\96\D0\BB\D1\8C\D1\88\D0\B5"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load217 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load217, i32 0, i32 43
  %load218 = load ptr, ptr %inst, align 8
  %load219 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load220 = load ptr, ptr %"\D0\A0", align 8
  %load221 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load218(ptr %load219, ptr %load220, ptr %load221)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load216 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load216
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BC\D0\B5\D0\BD\D1\88\D0\B5"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load223 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load223, i32 0, i32 44
  %load224 = load ptr, ptr %inst, align 8
  %load225 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load226 = load ptr, ptr %"\D0\A0", align 8
  %load227 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load224(ptr %load225, ptr %load226, ptr %load227)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load222 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load222
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\80\D1\96\D0\B2\D0\BD\D0\BE"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load229 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load229, i32 0, i32 45
  %load230 = load ptr, ptr %inst, align 8
  %load231 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load232 = load ptr, ptr %"\D0\A0", align 8
  %load233 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load230(ptr %load231, ptr %load232, ptr %load233)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load228 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load228
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BC\D1\96\D1\81\D1\82\D0\B8\D1\82\D1\8C"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load235 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load235, i32 0, i32 46
  %load236 = load ptr, ptr %inst, align 8
  %load237 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load238 = load ptr, ptr %"\D0\A0", align 8
  %load239 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load236(ptr %load237, ptr %load238, ptr %load239)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load234 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load234
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\94"(ptr %0, ptr %1, ptr %2) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %load241 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load241, i32 0, i32 47
  %load242 = load ptr, ptr %inst, align 8
  %load243 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load244 = load ptr, ptr %"\D0\A0", align 8
  %load245 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load242(ptr %load243, ptr %load244, ptr %load245)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load240 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load240
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B2\D1\96\D0\B4\CA\BC\D1\94\D0\BC\D0\BD\D0\B5"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load247 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load247, i32 0, i32 48
  %load248 = load ptr, ptr %inst, align 8
  %load249 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load250 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load248(ptr %load249, ptr %load250)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load246 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load246
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\BE\D0\B2\D0\B5"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load252 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load252, i32 0, i32 49
  %load253 = load ptr, ptr %inst, align 8
  %load254 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load255 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load253(ptr %load254, ptr %load255)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load251 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load251
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\B0\D0\BF\D0\B5\D1\80\D0\B5\D1\87\D0\B8\D1\82\D0\B8"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load257 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load257, i32 0, i32 50
  %load258 = load ptr, ptr %inst, align 8
  %load259 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load260 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load258(ptr %load259, ptr %load260)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load256 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load256
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\B1\D1\96\D0\BB\D1\8C\D1\88\D0\B8\D1\82\D0\B8"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load262 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load262, i32 0, i32 51
  %load263 = load ptr, ptr %inst, align 8
  %load264 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load265 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load263(ptr %load264, ptr %load265)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load261 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load261
}

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\BC\D0\B5\D0\BD\D1\88\D0\B8\D1\82\D0\B8"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load267 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load267, i32 0, i32 52
  %load268 = load ptr, ptr %inst, align 8
  %load269 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load270 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load268(ptr %load269, ptr %load270)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load266 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load266
}

declare i32 @putchar(i8)

define void @"\D0\B7\D0\B0\D0\B2\D0\B0\D0\BD\D1\82\D0\B0\D0\B6\D0\B8\D1\82\D0\B8_\D0\A0\D0\9C\D0\B21"(ptr %0) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BF" = alloca i8, align 1
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D0\BB\D0\BE\D0\B2\D0\BD\D0\B8\D0\BA\D0\B0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store i8 32, ptr %"\D0\BF", align 1
  br label %while_cond

return:                                           ; preds = %while_body_exit
  ret void

while_cond:                                       ; preds = %while_body, %entry
  %load271 = load i8, ptr %"\D0\BF", align 1
  %inst = icmp slt i8 %load271, 127
  br i1 %inst, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load272 = load i8, ptr %"\D0\BF", align 1
  %inst1 = call i32 @putchar(i8 %load272)
  %load273 = load i8, ptr %"\D0\BF", align 1
  %inst2 = add i8 %load273, 1
  store i8 %inst2, ptr %"\D0\BF", align 1
  br label %while_cond

while_body_exit:                                  ; preds = %while_cond
  %inst3 = call i32 @putchar(i8 10)
  %load274 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\AE8"(ptr @0, ptr %load274)
  %load275 = load ptr, ptr %"\D0\A0", align 8
  %inst4 = call ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA"(ptr %load275)
  store ptr %inst4, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D0\BB\D0\BE\D0\B2\D0\BD\D0\B8\D0\BA\D0\B0", align 8
  %load276 = load ptr, ptr %"\D0\A0", align 8
  %load277 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D0\BB\D0\BE\D0\B2\D0\BD\D0\B8\D0\BA\D0\B0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B3\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load276, ptr %load277)
  %load278 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D0\BB\D0\BE\D0\B2\D0\BD\D0\B8\D0\BA\D0\B0", align 8
  %load279 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load278, ptr %load279, i64 0)
  %load280 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\B2\D0\B8\D0\B4\D0\B0\D0\BB\D0\B8\D1\82\D0\B8_\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B6\D0\B5\D0\BD\D0\B8\D0\B9_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load280)
  br label %return
}
