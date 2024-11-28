; ModuleID = '/home/kohutd/CLionProjects/mavka-1.0.0/./непотріб/розширення_привіт.ц'
source_filename = "/home/kohutd/CLionProjects/mavka-1.0.0/./\D0\BD\D0\B5\D0\BF\D0\BE\D1\82\D1\80\D1\96\D0\B1/\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F_\D0\BF\D1\80\D0\B8\D0\B2\D1\96\D1\82.\D1\86"

%"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F" = type { %"\D0\A0\D0\9C\D0\B21::\D0\92\D0\B5\D1\80\D1\81\D1\96\D1\8F\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr }
%"\D0\A0\D0\9C\D0\B21::\D0\92\D0\B5\D1\80\D1\81\D1\96\D1\8F\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F" = type { i64, i64, i64 }
%"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" = type { ptr, ptr }

@0 = private constant [14 x i8] c"Hello, world!\00"
@1 = private constant [5 x i8] c"\D0\9F\D0\86\00"
@2 = private constant [64 x i8] c"\D0\9F\D0\BE\D0\BC\D0\B8\D0\BB\D0\BA\D0\B0 \D0\B7\D0\BC\D1\96\D0\BD\D0\B8 \D0\B2\D0\BB\D0\B0\D1\81\D1\82\D0\B8\D0\B2\D0\BE\D1\81\D1\82\D1\96 \D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82\D0\B0\00"
@3 = private constant [56 x i8] c"\D0\9F\D0\BE\D0\BC\D0\B8\D0\BB\D0\BA\D0\B0 \D0\B7\D0\BC\D1\96\D0\BD\D0\B8 \D0\B5\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\B0 \D1\81\D0\BF\D0\B8\D1\81\D0\BA\D1\83\00"

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

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B2\D0\B8\D0\BA\D0\BE\D0\BD\D0\B0\D1\82\D0\B8"(ptr %0, ptr %1, ptr %2, i64 %3, ptr %4) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\8F" = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2" = alloca i64, align 8
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  store ptr %2, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\8F", align 8
  store i64 %3, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2", align 4
  store ptr %4, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8", align 8
  %load82 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load82, i32 0, i32 21
  %load83 = load ptr, ptr %inst, align 8
  %load84 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load85 = load ptr, ptr %"\D0\A0", align 8
  %load86 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\8F", align 8
  %load87 = load i64, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2", align 4
  %load88 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load83(ptr %load84, ptr %load85, ptr %load86, i64 %load87, ptr %load88)
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
  %load90 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load90, i32 0, i32 22
  %load91 = load ptr, ptr %inst, align 8
  %load92 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load93 = load ptr, ptr %"\D0\A0", align 8
  %load94 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load91(ptr %load92, ptr %load93, ptr %load94)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load89 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load89
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
  %load96 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load96, i32 0, i32 23
  %load97 = load ptr, ptr %inst, align 8
  %load98 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load99 = load ptr, ptr %"\D0\A0", align 8
  %load100 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load101 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load97(ptr %load98, ptr %load99, ptr %load100, ptr %load101)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load95 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load95
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
  %load103 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load103, i32 0, i32 24
  %load104 = load ptr, ptr %inst, align 8
  %load105 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load106 = load ptr, ptr %"\D0\A0", align 8
  %load107 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load104(ptr %load105, ptr %load106, ptr %load107)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load102 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load102
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
  %load109 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load109, i32 0, i32 25
  %load110 = load ptr, ptr %inst, align 8
  %load111 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load112 = load ptr, ptr %"\D0\A0", align 8
  %load113 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load114 = load i64, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D1\96\D0\B2", align 4
  %load115 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\B8", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load110(ptr %load111, ptr %load112, ptr %load113, i64 %load114, ptr %load115)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load108 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load108
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
  %load117 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load117, i32 0, i32 26
  %load118 = load ptr, ptr %inst, align 8
  %load119 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load120 = load ptr, ptr %"\D0\A0", align 8
  %load121 = load ptr, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load118(ptr %load119, ptr %load120, ptr %load121)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load116 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load116
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
  %load123 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load123, i32 0, i32 27
  %load124 = load ptr, ptr %inst, align 8
  %load125 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load126 = load ptr, ptr %"\D0\A0", align 8
  %load127 = load ptr, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  %load128 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load124(ptr %load125, ptr %load126, ptr %load127, ptr %load128)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load122 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load122
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
  %load130 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load130, i32 0, i32 28
  %load131 = load ptr, ptr %inst, align 8
  %load132 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load133 = load ptr, ptr %"\D0\A0", align 8
  %load134 = load ptr, ptr %"\D0\BA\D0\BB\D1\8E\D1\87", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load131(ptr %load132, ptr %load133, ptr %load134)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load129 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load129
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
  %load136 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load136, i32 0, i32 29
  %load137 = load ptr, ptr %inst, align 8
  %load138 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load139 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load137(ptr %load138, ptr %load139)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load135 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load135
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
  %load141 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load141, i32 0, i32 30
  %load142 = load ptr, ptr %inst, align 8
  %load143 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load144 = load ptr, ptr %"\D0\A0", align 8
  %load145 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load142(ptr %load143, ptr %load144, ptr %load145)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load140 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load140
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
  %load147 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load147, i32 0, i32 31
  %load148 = load ptr, ptr %inst, align 8
  %load149 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load150 = load ptr, ptr %"\D0\A0", align 8
  %load151 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load148(ptr %load149, ptr %load150, ptr %load151)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load146 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load146
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
  %load153 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load153, i32 0, i32 32
  %load154 = load ptr, ptr %inst, align 8
  %load155 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load156 = load ptr, ptr %"\D0\A0", align 8
  %load157 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load154(ptr %load155, ptr %load156, ptr %load157)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load152 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load152
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
  %load159 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load159, i32 0, i32 33
  %load160 = load ptr, ptr %inst, align 8
  %load161 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load162 = load ptr, ptr %"\D0\A0", align 8
  %load163 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load160(ptr %load161, ptr %load162, ptr %load163)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load158 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load158
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
  %load165 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load165, i32 0, i32 34
  %load166 = load ptr, ptr %inst, align 8
  %load167 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load168 = load ptr, ptr %"\D0\A0", align 8
  %load169 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load166(ptr %load167, ptr %load168, ptr %load169)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load164 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load164
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
  %load171 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load171, i32 0, i32 35
  %load172 = load ptr, ptr %inst, align 8
  %load173 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load174 = load ptr, ptr %"\D0\A0", align 8
  %load175 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load172(ptr %load173, ptr %load174, ptr %load175)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load170 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load170
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
  %load177 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load177, i32 0, i32 36
  %load178 = load ptr, ptr %inst, align 8
  %load179 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load180 = load ptr, ptr %"\D0\A0", align 8
  %load181 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load178(ptr %load179, ptr %load180, ptr %load181)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load176 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load176
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
  %load183 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load183, i32 0, i32 37
  %load184 = load ptr, ptr %inst, align 8
  %load185 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load186 = load ptr, ptr %"\D0\A0", align 8
  %load187 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load184(ptr %load185, ptr %load186, ptr %load187)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load182 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load182
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
  %load189 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load189, i32 0, i32 38
  %load190 = load ptr, ptr %inst, align 8
  %load191 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load192 = load ptr, ptr %"\D0\A0", align 8
  %load193 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load190(ptr %load191, ptr %load192, ptr %load193)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load188 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load188
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
  %load195 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load195, i32 0, i32 39
  %load196 = load ptr, ptr %inst, align 8
  %load197 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load198 = load ptr, ptr %"\D0\A0", align 8
  %load199 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load196(ptr %load197, ptr %load198, ptr %load199)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load194 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load194
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
  %load201 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load201, i32 0, i32 40
  %load202 = load ptr, ptr %inst, align 8
  %load203 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load204 = load ptr, ptr %"\D0\A0", align 8
  %load205 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load202(ptr %load203, ptr %load204, ptr %load205)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load200 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load200
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
  %load207 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load207, i32 0, i32 41
  %load208 = load ptr, ptr %inst, align 8
  %load209 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load210 = load ptr, ptr %"\D0\A0", align 8
  %load211 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load208(ptr %load209, ptr %load210, ptr %load211)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load206 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load206
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
  %load213 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load213, i32 0, i32 42
  %load214 = load ptr, ptr %inst, align 8
  %load215 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load216 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load214(ptr %load215, ptr %load216)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load212 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load212
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
  %load218 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load218, i32 0, i32 43
  %load219 = load ptr, ptr %inst, align 8
  %load220 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load221 = load ptr, ptr %"\D0\A0", align 8
  %load222 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load219(ptr %load220, ptr %load221, ptr %load222)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load217 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load217
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
  %load224 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load224, i32 0, i32 44
  %load225 = load ptr, ptr %inst, align 8
  %load226 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load227 = load ptr, ptr %"\D0\A0", align 8
  %load228 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load225(ptr %load226, ptr %load227, ptr %load228)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load223 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load223
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
  %load230 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load230, i32 0, i32 45
  %load231 = load ptr, ptr %inst, align 8
  %load232 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load233 = load ptr, ptr %"\D0\A0", align 8
  %load234 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load231(ptr %load232, ptr %load233, ptr %load234)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load229 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load229
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
  %load236 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load236, i32 0, i32 46
  %load237 = load ptr, ptr %inst, align 8
  %load238 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load239 = load ptr, ptr %"\D0\A0", align 8
  %load240 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load237(ptr %load238, ptr %load239, ptr %load240)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load235 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load235
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
  %load242 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load242, i32 0, i32 47
  %load243 = load ptr, ptr %inst, align 8
  %load244 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load245 = load ptr, ptr %"\D0\A0", align 8
  %load246 = load ptr, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load243(ptr %load244, ptr %load245, ptr %load246)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load241 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load241
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
  %load248 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load248, i32 0, i32 48
  %load249 = load ptr, ptr %inst, align 8
  %load250 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load251 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load249(ptr %load250, ptr %load251)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load247 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load247
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
  %load253 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load253, i32 0, i32 49
  %load254 = load ptr, ptr %inst, align 8
  %load255 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load256 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load254(ptr %load255, ptr %load256)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load252 = load %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %return1, align 8
  ret %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %load252
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
  %load258 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load258, i32 0, i32 50
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

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\B1\D1\96\D0\BB\D1\8C\D1\88\D0\B8\D1\82\D0\B8"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load263 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load263, i32 0, i32 51
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

define internal %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\BC\D0\B5\D0\BD\D1\88\D0\B8\D1\82\D0\B8"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load268 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load268, i32 0, i32 52
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

declare i32 @putchar(i8)

define void @"\D0\B7\D0\B0\D0\B2\D0\B0\D0\BD\D1\82\D0\B0\D0\B6\D0\B8\D1\82\D0\B8_\D0\A0\D0\9C\D0\B21"(ptr %0) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BF" = alloca i8, align 1
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BC\D0\BE\D0\B4\D1\83\D0\BB\D1\8F_\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0_\D0\9F\D0\86" = alloca ptr, align 8
  %"\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82_\D0\B7\D0\BC\D1\96\D0\BD\D0\B8_\D0\B2\D0\BB\D0\B0\D1\81\D1\82\D0\B8\D0\B2\D0\BE\D1\81\D1\82\D1\96" = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D0\BF\D0\B8\D1\81\D0\BA\D1\83" = alloca ptr, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0_\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\97_0" = alloca ptr, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F_\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\97_0" = alloca ptr, align 8
  %"\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82_\D0\B7\D0\BC\D1\96\D0\BD\D0\B8_\D0\B5\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\B0" = alloca %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store i8 32, ptr %"\D0\BF", align 1
  br label %while_cond

return:                                           ; preds = %if_body_exit18, %if_body16, %if_body
  ret void

while_cond:                                       ; preds = %while_body, %entry
  %load272 = load i8, ptr %"\D0\BF", align 1
  %inst = icmp slt i8 %load272, 127
  br i1 %inst, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load273 = load i8, ptr %"\D0\BF", align 1
  %inst1 = call i32 @putchar(i8 %load273)
  %load274 = load i8, ptr %"\D0\BF", align 1
  %inst2 = add i8 %load274, 1
  store i8 %inst2, ptr %"\D0\BF", align 1
  br label %while_cond

while_body_exit:                                  ; preds = %while_cond
  %inst3 = call i32 @putchar(i8 10)
  %load275 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\AE8"(ptr @0, ptr %load275)
  %load276 = load ptr, ptr %"\D0\A0", align 8
  %inst4 = call ptr @"\D0\A0\D0\9C\D0\B21::\D0\BE\D1\82\D1\80\D0\B8\D0\BC\D0\B0\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BC\D0\BE\D0\B4\D1\83\D0\BB\D1\8F_\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F"(ptr %load276)
  store ptr %inst4, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BC\D0\BE\D0\B4\D1\83\D0\BB\D1\8F_\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load277 = load ptr, ptr %"\D0\A0", align 8
  %inst5 = call ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\87\D0\B8\D1\81\D0\BB\D0\BE"(ptr %load277, double 3.140000e+00)
  store ptr %inst5, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0_\D0\9F\D0\86", align 8
  %load278 = load ptr, ptr %"\D0\A0", align 8
  %load279 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0_\D0\9F\D0\86", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B3\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load278, ptr %load279)
  %load280 = load ptr, ptr %"\D0\A0", align 8
  %inst6 = call ptr @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0_\D0\B7_\D0\AE8"(ptr %load280, ptr @1)
  %load281 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BC\D0\BE\D0\B4\D1\83\D0\BB\D1\8F_\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load282 = load ptr, ptr %"\D0\A0", align 8
  %load283 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0_\D0\9F\D0\86", align 8
  %inst7 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\BC\D1\96\D0\BD\D0\B8\D1\82\D0\B8_\D0\B2\D0\BB\D0\B0\D1\81\D1\82\D0\B8\D0\B2\D1\96\D1\81\D1\82\D1\8C"(ptr %load281, ptr %load282, ptr %inst6, ptr %load283)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst7, ptr %"\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82_\D0\B7\D0\BC\D1\96\D0\BD\D0\B8_\D0\B2\D0\BB\D0\B0\D1\81\D1\82\D0\B8\D0\B2\D0\BE\D1\81\D1\82\D1\96", align 8
  %inst8 = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %"\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82_\D0\B7\D0\BC\D1\96\D0\BD\D0\B8_\D0\B2\D0\BB\D0\B0\D1\81\D1\82\D0\B8\D0\B2\D0\BE\D1\81\D1\82\D1\96", i32 0, i32 0
  %load284 = load ptr, ptr %inst8, align 8
  %inst9 = icmp ne ptr %load284, null
  br i1 %inst9, label %if_body, label %if_body_else

if_body:                                          ; preds = %while_body_exit
  %load285 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\AE8"(ptr @2, ptr %load285)
  br label %return
  br label %if_body_exit

if_body_else:                                     ; preds = %while_body_exit
  br label %if_body_exit

if_body_exit:                                     ; preds = %if_body_else, %if_body
  %load286 = load ptr, ptr %"\D0\A0", align 8
  %inst10 = call ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\81\D0\BF\D0\B8\D1\81\D0\BE\D0\BA"(ptr %load286)
  store ptr %inst10, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D0\BF\D0\B8\D1\81\D0\BA\D1\83", align 8
  %load287 = load ptr, ptr %"\D0\A0", align 8
  %load288 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D0\BF\D0\B8\D1\81\D0\BA\D1\83", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B3\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load287, ptr %load288)
  %load289 = load ptr, ptr %"\D0\A0", align 8
  %inst11 = call ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\87\D0\B8\D1\81\D0\BB\D0\BE"(ptr %load289, double 0.000000e+00)
  store ptr %inst11, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0_\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\97_0", align 8
  %load290 = load ptr, ptr %"\D0\A0", align 8
  %load291 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0_\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\97_0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B3\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load290, ptr %load291)
  %load292 = load ptr, ptr %"\D0\A0", align 8
  %inst12 = call ptr @"\D0\A0\D0\9C\D0\B21::\D1\81\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D1\87\D0\B8\D1\81\D0\BB\D0\BE"(ptr %load292, double 4.200000e+01)
  store ptr %inst12, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F_\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\97_0", align 8
  %load293 = load ptr, ptr %"\D0\A0", align 8
  %load294 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F_\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\97_0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B3\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load293, ptr %load294)
  %load295 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D0\BF\D0\B8\D1\81\D0\BA\D1\83", align 8
  %load296 = load ptr, ptr %"\D0\A0", align 8
  %load297 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0_\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\97_0", align 8
  %load298 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F_\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\97_0", align 8
  %inst13 = call %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" @"\D0\A0\D0\9C\D0\B21::\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D0\BC\D1\96\D0\BD\D0\B8\D1\82\D0\B8_\D0\B5\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82"(ptr %load295, ptr %load296, ptr %load297, ptr %load298)
  store %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82" %inst13, ptr %"\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82_\D0\B7\D0\BC\D1\96\D0\BD\D0\B8_\D0\B5\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\B0", align 8
  %load299 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\B2\D0\B8\D0\B4\D0\B0\D0\BB\D0\B8\D1\82\D0\B8_\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B6\D0\B5\D0\BD\D0\B8\D0\B9_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load299)
  %load300 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\B2\D0\B8\D0\B4\D0\B0\D0\BB\D0\B8\D1\82\D0\B8_\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B6\D0\B5\D0\BD\D0\B8\D0\B9_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load300)
  %load301 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\B2\D0\B8\D0\B4\D0\B0\D0\BB\D0\B8\D1\82\D0\B8_\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B6\D0\B5\D0\BD\D0\B8\D0\B9_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load301)
  %load302 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\B2\D0\B8\D0\B4\D0\B0\D0\BB\D0\B8\D1\82\D0\B8_\D0\B7\D0\B1\D0\B5\D1\80\D0\B5\D0\B6\D0\B5\D0\BD\D0\B8\D0\B9_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load302)
  %inst14 = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82", ptr %"\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D0\B0\D1\82_\D0\B7\D0\BC\D1\96\D0\BD\D0\B8_\D0\B5\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\B0", i32 0, i32 0
  %load303 = load ptr, ptr %inst14, align 8
  %inst15 = icmp ne ptr %load303, null
  br i1 %inst15, label %if_body16, label %if_body_else17

if_body16:                                        ; preds = %if_body_exit
  %load304 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\AE8"(ptr @3, ptr %load304)
  br label %return
  br label %if_body_exit18

if_body_else17:                                   ; preds = %if_body_exit
  br label %if_body_exit18

if_body_exit18:                                   ; preds = %if_body_else17, %if_body16
  %load305 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D0\BF\D0\B8\D1\81\D0\BA\D1\83", align 8
  %load306 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load305, ptr %load306, i64 0)
  br label %return
}
