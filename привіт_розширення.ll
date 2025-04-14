; ModuleID = '/home/kohutd/CLionProjects/mavka-1.0.0/привіт_розширення.ц'
source_filename = "/home/kohutd/CLionProjects/mavka-1.0.0/\D0\BF\D1\80\D0\B8\D0\B2\D1\96\D1\82_\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F.\D1\86"

%"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F" = type { ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr }
%"\D1\8E8" = type { i64, ptr }
%"\D0\A0\D0\9C\D0\B21::\D0\9C\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F" = type { ptr, i64 }

@0 = private constant [14 x i8] c"\D0\9F\D1\80\D0\B8\D0\B2\D1\96\D1\82!\00"

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\BC\D1\96\D0\BD\D0\B8\D1\82\D0\B8_\D0\B4\D0\B0\D0\BD\D1\96"(ptr %0, ptr %1) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load1 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load1, i32 0, i32 1
  %load2 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store ptr %load2, ptr %inst, align 8
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\BC\D1\96\D0\BD\D0\B8\D1\82\D0\B8_\D0\B2\D1\96\D0\B4\D0\BA\D0\BB\D0\B8\D0\BA_\D0\BF\D0\B5\D1\80\D0\B5\D0\B4_\D0\B7\D0\B2\D1\96\D0\BB\D1\8C\D0\BD\D0\B5\D0\BD\D0\BD\D1\8F\D0\BC"(ptr %0, ptr %1) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B2\D1\96\D0\B4\D0\BA\D0\BB\D0\B8\D0\BA_\D0\BF\D0\B5\D1\80\D0\B5\D0\B4_\D0\B7\D0\B2\D1\96\D0\BB\D1\8C\D0\BD\D0\B5\D0\BD\D0\BD\D1\8F\D0\BC" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B2\D1\96\D0\B4\D0\BA\D0\BB\D0\B8\D0\BA_\D0\BF\D0\B5\D1\80\D0\B5\D0\B4_\D0\B7\D0\B2\D1\96\D0\BB\D1\8C\D0\BD\D0\B5\D0\BD\D0\BD\D1\8F\D0\BC", align 8
  %load3 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load3, i32 0, i32 2
  %load4 = load ptr, ptr %"\D0\B2\D1\96\D0\B4\D0\BA\D0\BB\D0\B8\D0\BA_\D0\BF\D0\B5\D1\80\D0\B5\D0\B4_\D0\B7\D0\B2\D1\96\D0\BB\D1\8C\D0\BD\D0\B5\D0\BD\D0\BD\D1\8F\D0\BC", align 8
  store ptr %load4, ptr %inst, align 8
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\B2\D0\B8\D0\B2\D0\B5\D1\81\D1\82\D0\B8_\D1\8E8"(ptr %0, %"\D1\8E8" %1) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca %"\D1\8E8", align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store %"\D1\8E8" %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load5 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load5, i32 0, i32 3
  %load6 = load ptr, ptr %inst, align 8
  %load7 = load ptr, ptr %"\D0\A0", align 8
  %load8 = load %"\D1\8E8", ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void %load6(ptr %load7, %"\D1\8E8" %load8)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D1\8E8"(ptr %0, %"\D1\8E8" %1) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca %"\D1\8E8", align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store %"\D1\8E8" %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load9 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load9, i32 0, i32 4
  %load10 = load ptr, ptr %inst, align 8
  %load11 = load ptr, ptr %"\D0\A0", align 8
  %load12 = load %"\D1\8E8", ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void %load10(ptr %load11, %"\D1\8E8" %load12)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal i1 @"\D0\A0\D0\9C\D0\B21::\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D1\96\D1\80\D0\B8\D1\82\D0\B8_\D1\87\D0\B8_\D1\81\D1\82\D0\B0\D0\BD_\D0\BF\D0\B0\D0\B4\D1\96\D0\BD\D0\BD\D1\8F"(ptr %0) {
alloca:
  %return1 = alloca i1, align 1
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load14 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load14, i32 0, i32 5
  %load15 = load ptr, ptr %inst, align 8
  %load16 = load ptr, ptr %"\D0\A0", align 8
  %inst2 = call i1 %load15(ptr %load16)
  store i1 %inst2, ptr %return1, align 1
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load13 = load i1, ptr %return1, align 1
  ret i1 %load13
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D1\83\D0\B2\D1\96\D0\BC\D0\BA\D0\BD\D1\83\D1\82\D0\B8_\D1\81\D1\82\D0\B0\D0\BD_\D0\BF\D0\B0\D0\B4\D1\96\D0\BD\D0\BD\D1\8F"(ptr %0, %"\D0\A0\D0\9C\D0\B21::\D0\9C\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F" %1) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\BC\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F" = alloca %"\D0\A0\D0\9C\D0\B21::\D0\9C\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store %"\D0\A0\D0\9C\D0\B21::\D0\9C\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F" %1, ptr %"\D0\BC\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load17 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load17, i32 0, i32 6
  %load18 = load ptr, ptr %inst, align 8
  %load19 = load ptr, ptr %"\D0\A0", align 8
  %load20 = load %"\D0\A0\D0\9C\D0\B21::\D0\9C\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F", ptr %"\D0\BC\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void %load18(ptr %load19, %"\D0\A0\D0\9C\D0\B21::\D0\9C\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F" %load20)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\B2\D0\B8\D0\BC\D0\BA\D0\BD\D1\83\D1\82\D0\B8_\D1\81\D1\82\D0\B0\D0\BD_\D0\BF\D0\B0\D0\B4\D1\96\D0\BD\D0\BD\D1\8F"(ptr %0) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load21 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load21, i32 0, i32 7
  %load22 = load ptr, ptr %inst, align 8
  %load23 = load ptr, ptr %"\D0\A0", align 8
  call void %load22(ptr %load23)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D0\BF\D0\B0\D0\B4\D1\96\D0\BD\D0\BD\D1\8F"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %construct = alloca %"\D0\A0\D0\9C\D0\B21::\D0\9C\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\9C\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F", ptr %construct, i32 0, i32 0
  store ptr null, ptr %inst, align 8
  %inst2 = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\9C\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F", ptr %construct, i32 0, i32 1
  store i64 0, ptr %inst2, align 4
  %load25 = load ptr, ptr %"\D0\A0", align 8
  %load26 = load %"\D0\A0\D0\9C\D0\B21::\D0\9C\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F", ptr %construct, align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D1\83\D0\B2\D1\96\D0\BC\D0\BA\D0\BD\D1\83\D1\82\D0\B8_\D1\81\D1\82\D0\B0\D0\BD_\D0\BF\D0\B0\D0\B4\D1\96\D0\BD\D0\BD\D1\8F"(ptr %load25, %"\D0\A0\D0\9C\D0\B21::\D0\9C\D1\96\D1\81\D1\86\D0\B5\D0\B7\D0\BD\D0\B0\D1\85\D0\BE\D0\B4\D0\B6\D0\B5\D0\BD\D0\BD\D1\8F" %load26)
  %load27 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store ptr %load27, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load24 = load ptr, ptr %return1, align 8
  ret ptr %load24
}

define ptr @"\D0\B7\D0\B0\D0\B2\D0\B0\D0\BD\D1\82\D0\B0\D0\B6\D0\B8\D1\82\D0\B8_\D0\A0\D0\9C\D0\B21"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  %construct = alloca %"\D1\8E8", align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D1\8E8", ptr %construct, i32 0, i32 1
  store ptr @0, ptr %inst, align 8
  %inst2 = getelementptr %"\D1\8E8", ptr %construct, i32 0, i32 0
  store i64 13, ptr %inst2, align 4
  %load29 = load ptr, ptr %"\D0\A0", align 8
  %load30 = load %"\D1\8E8", ptr %construct, align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D1\8E8"(ptr %load29, %"\D1\8E8" %load30)
  store ptr null, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load28 = load ptr, ptr %return1, align 8
  ret ptr %load28
}
