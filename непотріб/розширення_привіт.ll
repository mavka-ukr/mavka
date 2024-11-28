; ModuleID = '/home/kohutd/CLionProjects/mavka-1.0.0/./непотріб/розширення_привіт.ц'
source_filename = "/home/kohutd/CLionProjects/mavka-1.0.0/./\D0\BD\D0\B5\D0\BF\D0\BE\D1\82\D1\80\D1\96\D0\B1/\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F_\D0\BF\D1\80\D0\B8\D0\B2\D1\96\D1\82.\D1\86"

%"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F" = type { %"\D0\A0\D0\9C\D0\B21::\D0\92\D0\B5\D1\80\D1\81\D1\96\D1\8F\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr }
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

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D0\BE\D1\82\D1\80\D0\B8\D0\BC\D0\B0\D1\82\D0\B8_\D0\B3\D0\BB\D0\BE\D0\B1\D0\B0\D0\BB\D1\8C\D0\BD\D0\B5_\D1\81\D0\B5\D1\80\D0\B5\D0\B4\D0\BE\D0\B2\D0\B8\D1\89\D0\B5"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load32 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load32, i32 0, i32 10
  %load33 = load ptr, ptr %inst, align 8
  %load34 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call ptr %load33(ptr %load34)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load31 = load ptr, ptr %return1, align 8
  ret ptr %load31
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D0\BF\D0\BE\D0\BA\D0\BB\D0\B0\D1\81\D1\82\D0\B8_\D1\82\D0\B8\D0\BC\D1\87\D0\B0\D1\81\D0\BE\D0\B2\D0\B5_\D1\81\D0\B5\D1\80\D0\B5\D0\B4\D0\BE\D0\B2\D0\B8\D1\89\D0\B5"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load36 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load36, i32 0, i32 11
  %load37 = load ptr, ptr %inst, align 8
  %load38 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call ptr %load37(ptr %load38)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load35 = load ptr, ptr %return1, align 8
  ret ptr %load35
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\B0\D0\B1\D1\80\D0\B0\D1\82\D0\B8_\D1\82\D0\B8\D0\BC\D1\87\D0\B0\D1\81\D0\BE\D0\B2\D0\B5_\D1\81\D0\B5\D1\80\D0\B5\D0\B4\D0\BE\D0\B2\D0\B8\D1\89\D0\B5"(ptr %0) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load39 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load39, i32 0, i32 12
  %load40 = load ptr, ptr %inst, align 8
  %load41 = load ptr, ptr %"\D0\A0", align 8
  call void %load40(ptr %load41)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\BF\D0\BE\D0\BA\D0\BB\D0\B0\D1\81\D1\82\D0\B8_\D0\B2_\D0\9D\D0\B0\D1\82\D0\9E"(ptr %0, ptr %1) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load42 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load42, i32 0, i32 13
  %load43 = load ptr, ptr %inst, align 8
  %load44 = load ptr, ptr %"\D0\A0", align 8
  %load45 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  call void %load43(ptr %load44, ptr %load45)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\B0\D0\B1\D1\80\D0\B0\D1\82\D0\B8_\D0\B7_\D0\9D\D0\B0\D1\82\D0\9E"(ptr %0) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load46 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load46, i32 0, i32 14
  %load47 = load ptr, ptr %inst, align 8
  %load48 = load ptr, ptr %"\D0\A0", align 8
  call void %load47(ptr %load48)
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
  %load50 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load50, i32 0, i32 15
  %load51 = load ptr, ptr %inst, align 8
  %load52 = load ptr, ptr %"\D0\A0", align 8
  %load53 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr %load51(ptr %load52, ptr %load53)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load49 = load ptr, ptr %return1, align 8
  ret ptr %load49
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
  %load55 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load55, i32 0, i32 16
  %load56 = load ptr, ptr %inst, align 8
  %load57 = load ptr, ptr %"\D0\A0", align 8
  %load58 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load59 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr %load56(ptr %load57, ptr %load58, ptr %load59)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load54 = load ptr, ptr %return1, align 8
  ret ptr %load54
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
  %load61 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load61, i32 0, i32 17
  %load62 = load ptr, ptr %inst, align 8
  %load63 = load ptr, ptr %"\D0\A0", align 8
  %load64 = load double, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr %load62(ptr %load63, double %load64)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load60 = load ptr, ptr %return1, align 8
  ret ptr %load60
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\82\D0\B5\D0\BA\D1\81\D1\82_\D0\B7_\D1\8E8"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load66 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load66, i32 0, i32 18
  %load67 = load ptr, ptr %inst, align 8
  %load68 = load ptr, ptr %"\D0\A0", align 8
  %load69 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr %load67(ptr %load68, ptr %load69)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load65 = load ptr, ptr %return1, align 8
  ret ptr %load65
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4_\D0\B7_\D1\8E8"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load71 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load71, i32 0, i32 19
  %load72 = load ptr, ptr %inst, align 8
  %load73 = load ptr, ptr %"\D0\A0", align 8
  %load74 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr %load72(ptr %load73, ptr %load74)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load70 = load ptr, ptr %return1, align 8
  ret ptr %load70
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
  %load76 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load76, i32 0, i32 20
  %load77 = load ptr, ptr %inst, align 8
  %load78 = load ptr, ptr %"\D0\A0", align 8
  %load79 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %inst2 = call ptr %load77(ptr %load78, ptr %load79)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load75 = load ptr, ptr %return1, align 8
  ret ptr %load75
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load81 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load81, i32 0, i32 21
  %load82 = load ptr, ptr %inst, align 8
  %load83 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call ptr %load82(ptr %load83)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load80 = load ptr, ptr %return1, align 8
  ret ptr %load80
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\81\D0\BB\D0\BE\D0\B2\D0\BD\D0\B8\D0\BA"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load85 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load85, i32 0, i32 22
  %load86 = load ptr, ptr %inst, align 8
  %load87 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call ptr %load86(ptr %load87)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load84 = load ptr, ptr %return1, align 8
  ret ptr %load84
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load89 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load89, i32 0, i32 23
  %load90 = load ptr, ptr %inst, align 8
  %load91 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call ptr %load90(ptr %load91)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load88 = load ptr, ptr %return1, align 8
  ret ptr %load88
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
  %load93 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load93, i32 0, i32 24
  %load94 = load ptr, ptr %inst, align 8
  %load95 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load96 = load ptr, ptr %"\D0\A0", align 8
  %load97 = load i64, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2", align 4
  %load98 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load94(ptr %load95, ptr %load96, i64 %load97, ptr %load98)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load92 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load92
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
  %load100 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load100, i32 0, i32 25
  %load101 = load ptr, ptr %inst, align 8
  %load102 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load103 = load ptr, ptr %"\D0\A0", align 8
  %load104 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load101(ptr %load102, ptr %load103, ptr %load104)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load99 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load99
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
  %load106 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load106, i32 0, i32 26
  %load107 = load ptr, ptr %inst, align 8
  %load108 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load109 = load ptr, ptr %"\D0\A0", align 8
  %load110 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load111 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load107(ptr %load108, ptr %load109, ptr %load110, ptr %load111)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load105 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load105
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
  %load113 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load113, i32 0, i32 27
  %load114 = load ptr, ptr %inst, align 8
  %load115 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load116 = load ptr, ptr %"\D0\A0", align 8
  %load117 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load114(ptr %load115, ptr %load116, ptr %load117)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load112 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load112
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
  %load119 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load119, i32 0, i32 28
  %load120 = load ptr, ptr %inst, align 8
  %load121 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load122 = load ptr, ptr %"\D0\A0", align 8
  %load123 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load124 = load i64, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2", align 4
  %load125 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load120(ptr %load121, ptr %load122, ptr %load123, i64 %load124, ptr %load125)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load118 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load118
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
  %load127 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load127, i32 0, i32 29
  %load128 = load ptr, ptr %inst, align 8
  %load129 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load130 = load ptr, ptr %"\D0\A0", align 8
  %load131 = load ptr, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load128(ptr %load129, ptr %load130, ptr %load131)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load126 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load126
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
  %load133 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load133, i32 0, i32 30
  %load134 = load ptr, ptr %inst, align 8
  %load135 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load136 = load ptr, ptr %"\D0\A0", align 8
  %load137 = load ptr, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  %load138 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load134(ptr %load135, ptr %load136, ptr %load137, ptr %load138)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load132 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load132
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
  %load140 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load140, i32 0, i32 31
  %load141 = load ptr, ptr %inst, align 8
  %load142 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load143 = load ptr, ptr %"\D0\A0", align 8
  %load144 = load ptr, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load141(ptr %load142, ptr %load143, ptr %load144)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load139 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load139
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
  %load146 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load146, i32 0, i32 32
  %load147 = load ptr, ptr %inst, align 8
  %load148 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load149 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load147(ptr %load148, ptr %load149)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load145 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load145
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
  %load151 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load151, i32 0, i32 33
  %load152 = load ptr, ptr %inst, align 8
  %load153 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load154 = load ptr, ptr %"\D0\A0", align 8
  %load155 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load152(ptr %load153, ptr %load154, ptr %load155)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load150 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load150
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
  %load157 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load157, i32 0, i32 34
  %load158 = load ptr, ptr %inst, align 8
  %load159 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load160 = load ptr, ptr %"\D0\A0", align 8
  %load161 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load158(ptr %load159, ptr %load160, ptr %load161)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load156 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load156
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
  %load163 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load163, i32 0, i32 35
  %load164 = load ptr, ptr %inst, align 8
  %load165 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load166 = load ptr, ptr %"\D0\A0", align 8
  %load167 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load164(ptr %load165, ptr %load166, ptr %load167)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load162 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load162
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
  %load169 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load169, i32 0, i32 36
  %load170 = load ptr, ptr %inst, align 8
  %load171 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load172 = load ptr, ptr %"\D0\A0", align 8
  %load173 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load170(ptr %load171, ptr %load172, ptr %load173)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load168 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load168
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
  %load175 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load175, i32 0, i32 37
  %load176 = load ptr, ptr %inst, align 8
  %load177 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load178 = load ptr, ptr %"\D0\A0", align 8
  %load179 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load176(ptr %load177, ptr %load178, ptr %load179)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load174 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load174
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
  %load181 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load181, i32 0, i32 38
  %load182 = load ptr, ptr %inst, align 8
  %load183 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load184 = load ptr, ptr %"\D0\A0", align 8
  %load185 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load182(ptr %load183, ptr %load184, ptr %load185)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load180 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load180
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
  %load187 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load187, i32 0, i32 39
  %load188 = load ptr, ptr %inst, align 8
  %load189 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load190 = load ptr, ptr %"\D0\A0", align 8
  %load191 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load188(ptr %load189, ptr %load190, ptr %load191)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load186 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load186
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
  %load193 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load193, i32 0, i32 40
  %load194 = load ptr, ptr %inst, align 8
  %load195 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load196 = load ptr, ptr %"\D0\A0", align 8
  %load197 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load194(ptr %load195, ptr %load196, ptr %load197)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load192 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load192
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
  %load199 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load199, i32 0, i32 41
  %load200 = load ptr, ptr %inst, align 8
  %load201 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load202 = load ptr, ptr %"\D0\A0", align 8
  %load203 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load200(ptr %load201, ptr %load202, ptr %load203)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load198 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load198
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
  %load205 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load205, i32 0, i32 42
  %load206 = load ptr, ptr %inst, align 8
  %load207 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load208 = load ptr, ptr %"\D0\A0", align 8
  %load209 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load206(ptr %load207, ptr %load208, ptr %load209)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load204 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load204
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
  %load211 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load211, i32 0, i32 43
  %load212 = load ptr, ptr %inst, align 8
  %load213 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load214 = load ptr, ptr %"\D0\A0", align 8
  %load215 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load212(ptr %load213, ptr %load214, ptr %load215)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load210 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load210
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
  %load217 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load217, i32 0, i32 44
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

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B4\D0\B2\D1\96\D0\B9\D0\BA\D0\BE\D0\B2\D0\B5_\D0\BD\D0\B5"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load223 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load223, i32 0, i32 45
  %load224 = load ptr, ptr %inst, align 8
  %load225 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load226 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load224(ptr %load225, ptr %load226)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load222 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load222
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
  %load228 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load228, i32 0, i32 46
  %load229 = load ptr, ptr %inst, align 8
  %load230 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load231 = load ptr, ptr %"\D0\A0", align 8
  %load232 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load229(ptr %load230, ptr %load231, ptr %load232)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load227 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load227
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
  %load234 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load234, i32 0, i32 47
  %load235 = load ptr, ptr %inst, align 8
  %load236 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load237 = load ptr, ptr %"\D0\A0", align 8
  %load238 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load235(ptr %load236, ptr %load237, ptr %load238)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load233 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load233
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
  %load240 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load240, i32 0, i32 48
  %load241 = load ptr, ptr %inst, align 8
  %load242 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load243 = load ptr, ptr %"\D0\A0", align 8
  %load244 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load241(ptr %load242, ptr %load243, ptr %load244)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load239 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load239
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
  %load246 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load246, i32 0, i32 49
  %load247 = load ptr, ptr %inst, align 8
  %load248 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load249 = load ptr, ptr %"\D0\A0", align 8
  %load250 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load247(ptr %load248, ptr %load249, ptr %load250)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load245 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load245
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
  %load252 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load252, i32 0, i32 50
  %load253 = load ptr, ptr %inst, align 8
  %load254 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load255 = load ptr, ptr %"\D0\A0", align 8
  %load256 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load253(ptr %load254, ptr %load255, ptr %load256)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load251 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load251
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
  %load258 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load258, i32 0, i32 51
  %load259 = load ptr, ptr %inst, align 8
  %load260 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load261 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load259(ptr %load260, ptr %load261)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load257 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load257
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
  %load263 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load263, i32 0, i32 52
  %load264 = load ptr, ptr %inst, align 8
  %load265 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load266 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load264(ptr %load265, ptr %load266)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load262 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load262
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
  %load268 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load268, i32 0, i32 53
  %load269 = load ptr, ptr %inst, align 8
  %load270 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load271 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load269(ptr %load270, ptr %load271)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load267 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load267
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
  %load273 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load273, i32 0, i32 54
  %load274 = load ptr, ptr %inst, align 8
  %load275 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load276 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load274(ptr %load275, ptr %load276)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load272 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load272
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
  %load278 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load278, i32 0, i32 55
  %load279 = load ptr, ptr %inst, align 8
  %load280 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load281 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load279(ptr %load280, ptr %load281)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load277 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load277
}

declare i32 @putchar(i8)

define void @"\D0\B7\D0\B0\D0\B2\D0\B0\D0\BD\D1\82\D0\B0\D0\B6\D0\B8\D1\82\D0\B8_\D0\A0\D0\9C\D0\B21"(ptr %0) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BF" = alloca i8, align 1
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store i8 32, ptr %"\D0\BF", align 1
  br label %while_cond

return:                                           ; preds = %while_body_exit
  ret void

while_cond:                                       ; preds = %while_body, %entry
  %load282 = load i8, ptr %"\D0\BF", align 1
  %inst = icmp slt i8 %load282, 127
  br i1 %inst, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load283 = load i8, ptr %"\D0\BF", align 1
  %inst1 = call i32 @putchar(i8 %load283)
  %load284 = load i8, ptr %"\D0\BF", align 1
  %inst2 = add i8 %load284, 1
  store i8 %inst2, ptr %"\D0\BF", align 1
  br label %while_cond

while_body_exit:                                  ; preds = %while_cond
  %inst3 = call i32 @putchar(i8 10)
  %load285 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\AE8"(ptr @0, ptr %load285)
  %load286 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr null, ptr %load286, i64 0)
  br label %return
}
