; ModuleID = '/home/kohutd/CLionProjects/mavka-1.0.0/./непотріб/розширення_привіт.ц'
source_filename = "/home/kohutd/CLionProjects/mavka-1.0.0/./\D0\BD\D0\B5\D0\BF\D0\BE\D1\82\D1\80\D1\96\D0\B1/\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F_\D0\BF\D1\80\D0\B8\D0\B2\D1\96\D1\82.\D1\86"

%"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F" = type { %"\D0\A0\D0\9C\D0\B21::\D0\92\D0\B5\D1\80\D1\81\D1\96\D1\8F\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr, ptr, ptr, ptr, ptr }
%"\D0\A0\D0\9C\D0\B21::\D0\92\D0\B5\D1\80\D1\81\D1\96\D1\8F\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F" = type { i64, i64, i64 }

@0 = private constant [14 x i8] c"Hello, world!\00"

define internal ptr @"\D0\A0\D0\9C\D0\B21::\D0\BE\D1\82\D1\80\D0\B8\D0\BC\D0\B0\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\BC\D0\BE\D0\B4\D1\83\D0\BB\D1\8F"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  %load2 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load2, i32 0, i32 2
  %load3 = load ptr, ptr %inst, align 8
  store ptr %load3, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load1 = load ptr, ptr %return1, align 8
  ret ptr %load1
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\B7\D0\B0\D0\BF\D0\B8\D1\81\D0\B0\D1\82\D0\B8_\D0\B4\D0\B0\D0\BD\D1\96_\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F"(ptr %0, ptr %1) {
alloca:
  %"\D0\A0" = alloca ptr, align 8
  %"\D0\B4\D0\B0\D0\BD\D1\96" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\A0", align 8
  store ptr %1, ptr %"\D0\B4\D0\B0\D0\BD\D1\96", align 8
  %load4 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load4, i32 0, i32 3
  %load5 = load ptr, ptr %"\D0\B4\D0\B0\D0\BD\D1\96", align 8
  store ptr %load5, ptr %inst, align 8
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D1\8E8"(ptr %0, ptr %1) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\A0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store ptr %1, ptr %"\D0\A0", align 8
  %load6 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load6, i32 0, i32 4
  %load7 = load ptr, ptr %inst, align 8
  %load8 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load9 = load ptr, ptr %"\D0\A0", align 8
  call void %load7(ptr %load8, ptr %load9)
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
  %load10 = load ptr, ptr %"\D0\A0", align 8
  %inst = getelementptr %"\D0\A0\D0\9C\D0\B21::\D0\A0\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F", ptr %load10, i32 0, i32 5
  %load11 = load ptr, ptr %inst, align 8
  %load12 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load13 = load ptr, ptr %"\D0\A0", align 8
  %load14 = load i64, ptr %"\D0\B3\D0\BB\D0\B8\D0\B1\D0\B8\D0\BD\D0\B0", align 4
  call void %load11(ptr %load12, ptr %load13, i64 %load14)
  br label %return

return:                                           ; preds = %entry
  ret void
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
  %load15 = load i8, ptr %"\D0\BF", align 1
  %inst = icmp slt i8 %load15, 127
  br i1 %inst, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load16 = load i8, ptr %"\D0\BF", align 1
  %inst1 = call i32 @putchar(i8 %load16)
  %load17 = load i8, ptr %"\D0\BF", align 1
  %inst2 = add i8 %load17, 1
  store i8 %inst2, ptr %"\D0\BF", align 1
  br label %while_cond

while_body_exit:                                  ; preds = %while_cond
  %inst3 = call i32 @putchar(i8 10)
  %load18 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D1\8E8"(ptr @0, ptr %load18)
  %load19 = load ptr, ptr %"\D0\A0", align 8
  call void @"\D0\A0\D0\9C\D0\B21::\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr null, ptr %load19, i64 0)
  br label %return
}
