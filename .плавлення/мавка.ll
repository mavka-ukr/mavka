; ModuleID = 'мавка.ц'
source_filename = "\D0\BC\D0\B0\D0\B2\D0\BA\D0\B0.\D1\86"

%"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4" = type { i32, ptr, i32, ptr, i32, ptr, i32, ptr, i32, ptr, i32, ptr }
%"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9D\D0\B0\D0\B7\D0\B2\D0\B0" = type { ptr }
%"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = type { ptr, %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", double, ptr }
%"\D0\9A\D0\B0\D1\80\D1\82\D0\B0" = type { i64, ptr, ptr }
%"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0" = type { %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr, ptr, ptr }
%"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2" = type { %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr }
%"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80" = type { i64, ptr }
%"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0" = type { i64, ptr }
%"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8" = type { ptr, ptr }

@0 = private constant [13 x i8] c"\D0\BF\D1\80\D0\B5\D0\B4\D0\BE\D0\BA\00"

declare ptr @mavka_ext_malloc(i32)

declare void @mavka_ext_free(ptr)

declare ptr @mavka_ext_realloc(ptr, i32)

declare i32 @mavka_ext_putchar(i8)

define internal void @"\D0\B7\D0\B2\D1\96\D0\BB\D1\8C\D0\BD\D0\B8\D1\82\D0\B8"(ptr %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load1 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  call void @mavka_ext_free(ptr %load1)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D1\8E8"(ptr %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D1\85" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store i64 0, ptr %"\D1\85", align 4
  br label %while_cond

return:                                           ; preds = %while_body_exit
  ret void

while_cond:                                       ; preds = %while_body, %entry
  %load2 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load3 = load i64, ptr %"\D1\85", align 4
  %inst = getelementptr i8, ptr %load2, i64 %load3
  %load4 = load i8, ptr %inst, align 1
  %inst1 = icmp ne i8 %load4, 0
  br i1 %inst1, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load5 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load6 = load i64, ptr %"\D1\85", align 4
  %inst2 = getelementptr i8, ptr %load5, i64 %load6
  %load7 = load i8, ptr %inst2, align 1
  %inst3 = call i32 @mavka_ext_putchar(i8 %load7)
  %load8 = load i64, ptr %"\D1\85", align 4
  %inst4 = add i64 %load8, 1
  store i64 %inst4, ptr %"\D1\85", align 4
  br label %while_cond

while_body_exit:                                  ; preds = %while_cond
  %inst5 = call i32 @mavka_ext_putchar(i8 10)
  br label %return
}

define internal ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D0\BF64_\D0\B2_\D1\8E8"(i64 %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i64, align 8
  %"\D0\B1\D1\83\D1\84\D0\B5\D1\80" = alloca ptr, align 8
  %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81" = alloca i32, align 4
  %"\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D1\83\D1\8E\D1\87\D0\B8\D0\B9_\D0\B1\D1\83\D1\84\D0\B5\D1\80" = alloca ptr, align 8
  %"\D1\85" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i64 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %inst = call ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.1"(i32 21)
  store ptr %inst, ptr %"\D0\B1\D1\83\D1\84\D0\B5\D1\80", align 8
  store i32 20, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %load13 = load ptr, ptr %"\D0\B1\D1\83\D1\84\D0\B5\D1\80", align 8
  %inst2 = getelementptr i8, ptr %load13, i32 20
  store i8 0, ptr %inst2, align 1
  br label %while_cond

return:                                           ; preds = %while_body_exit18, %while_body_exit18
  %load9 = load ptr, ptr %return1, align 8
  ret ptr %load9

while_cond:                                       ; preds = %while_body, %entry
  %load14 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %inst3 = icmp ugt i64 %load14, 0
  br i1 %inst3, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load15 = load i32, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %inst4 = sub i32 %load15, 1
  store i32 %inst4, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %load16 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %inst5 = urem i64 %load16, 10
  %inst6 = trunc i64 %inst5 to i8
  %inst7 = add i8 %inst6, 48
  %load17 = load ptr, ptr %"\D0\B1\D1\83\D1\84\D0\B5\D1\80", align 8
  %load18 = load i32, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %inst8 = getelementptr i8, ptr %load17, i32 %load18
  store i8 %inst7, ptr %inst8, align 1
  %load19 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %inst9 = udiv i64 %load19, 10
  store i64 %inst9, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  br label %while_cond

while_body_exit:                                  ; preds = %while_cond
  %load20 = load i32, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %inst10 = icmp eq i32 %load20, 20
  br i1 %inst10, label %if_body, label %if_body_else

if_body:                                          ; preds = %while_body_exit
  %load21 = load i32, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %inst11 = sub i32 %load21, 1
  store i32 %inst11, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %load22 = load ptr, ptr %"\D0\B1\D1\83\D1\84\D0\B5\D1\80", align 8
  %load23 = load i32, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %inst12 = getelementptr i8, ptr %load22, i32 %load23
  store i8 48, ptr %inst12, align 1
  br label %if_body_exit

if_body_else:                                     ; preds = %while_body_exit
  br label %if_body_exit

if_body_exit:                                     ; preds = %if_body_else, %if_body
  %load24 = load i32, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %inst13 = sub i32 21, %load24
  %inst14 = call ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.1"(i32 %inst13)
  store ptr %inst14, ptr %"\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D1\83\D1\8E\D1\87\D0\B8\D0\B9_\D0\B1\D1\83\D1\84\D0\B5\D1\80", align 8
  store i32 0, ptr %"\D1\85", align 4
  br label %while_cond15

while_cond15:                                     ; preds = %while_body17, %if_body_exit
  %load25 = load i32, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %inst16 = icmp slt i32 %load25, 21
  br i1 %inst16, label %while_body17, label %while_body_exit18

while_body17:                                     ; preds = %while_cond15
  %load26 = load ptr, ptr %"\D0\B1\D1\83\D1\84\D0\B5\D1\80", align 8
  %load27 = load i32, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %inst19 = getelementptr i8, ptr %load26, i32 %load27
  %load28 = load ptr, ptr %"\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D1\83\D1\8E\D1\87\D0\B8\D0\B9_\D0\B1\D1\83\D1\84\D0\B5\D1\80", align 8
  %load29 = load i32, ptr %"\D1\85", align 4
  %inst20 = getelementptr i8, ptr %load28, i32 %load29
  %load30 = load i8, ptr %inst19, align 1
  store i8 %load30, ptr %inst20, align 1
  %load31 = load i32, ptr %"\D1\85", align 4
  %inst21 = add i32 %load31, 1
  store i32 %inst21, ptr %"\D1\85", align 4
  %load32 = load i32, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  %inst22 = add i32 %load32, 1
  store i32 %inst22, ptr %"\D1\96\D0\BD\D0\B4\D0\B5\D0\BA\D1\81", align 4
  br label %while_cond15

while_body_exit18:                                ; preds = %while_cond15
  %load33 = load ptr, ptr %"\D0\B1\D1\83\D1\84\D0\B5\D1\80", align 8
  call void @"\D0\B7\D0\B2\D1\96\D0\BB\D1\8C\D0\BD\D0\B8\D1\82\D0\B8"(ptr %load33)
  %load34 = load ptr, ptr %"\D1\80\D0\B5\D0\B7\D1\83\D0\BB\D1\8C\D1\82\D1\83\D1\8E\D1\87\D0\B8\D0\B9_\D0\B1\D1\83\D1\84\D0\B5\D1\80", align 8
  store ptr %load34, ptr %return1, align 8
  br label %return
  br label %return
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8"() {
alloca:
  %return1 = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  %inst = call ptr @mavka_ext_malloc(i32 1)
  store ptr %inst, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load10 = load ptr, ptr %return1, align 8
  ret ptr %load10
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.1"(i32 %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load12 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %inst = mul i32 %load12, 1
  %inst2 = call ptr @mavka_ext_malloc(i32 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load11 = load ptr, ptr %return1, align 8
  ret ptr %load11
}

define internal ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D0\B464_\D0\B2_\D1\8E8"(double %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca double, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store double %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load36 = load double, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst = fptoui double %load36 to i64
  %inst2 = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D0\BF64_\D0\B2_\D1\8E8"(i64 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load35 = load ptr, ptr %return1, align 8
  ret ptr %load35
}

define internal void @"\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\BF64"(i64 %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca i64, align 8
  %"\D0\BF64\D1\8E8" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store i64 %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %load37 = load i64, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 4
  %inst = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D0\BF64_\D0\B2_\D1\8E8"(i64 %load37)
  store ptr %inst, ptr %"\D0\BF64\D1\8E8", align 8
  %load38 = load ptr, ptr %"\D0\BF64\D1\8E8", align 8
  call void @"\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D1\8E8"(ptr %load38)
  %load39 = load ptr, ptr %"\D0\BF64\D1\8E8", align 8
  call void @"\D0\B7\D0\B2\D1\96\D0\BB\D1\8C\D0\BD\D0\B8\D1\82\D0\B8"(ptr %load39)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal void @"\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\B464"(double %0) {
alloca:
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca double, align 8
  %"\D0\B464\D1\8E8" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store double %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load40 = load double, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D1\82\D0\B2\D0\BE\D1\80\D0\B8\D1\82\D0\B8_\D0\B464_\D0\B2_\D1\8E8"(double %load40)
  store ptr %inst, ptr %"\D0\B464\D1\8E8", align 8
  %load41 = load ptr, ptr %"\D0\B464\D1\8E8", align 8
  call void @"\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D1\8E8"(ptr %load41)
  %load42 = load ptr, ptr %"\D0\B464\D1\8E8", align 8
  call void @"\D0\B7\D0\B2\D1\96\D0\BB\D1\8C\D0\BD\D0\B8\D1\82\D0\B8"(ptr %load42)
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal double @fmod(double %0, double %1) {
alloca:
  %return1 = alloca double, align 8
  %a = alloca double, align 8
  %b = alloca double, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store double %0, ptr %a, align 8
  store double %1, ptr %b, align 8
  %load44 = load double, ptr %a, align 8
  %load45 = load double, ptr %a, align 8
  %load46 = load double, ptr %b, align 8
  %inst = fdiv double %load45, %load46
  %load47 = load double, ptr %b, align 8
  %inst2 = fmul double %inst, %load47
  %inst3 = fsub double %load44, %inst2
  store double %inst3, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load43 = load double, ptr %return1, align 8
  ret double %load43
}

define internal i1 @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D1\96\D1\80\D0\B8\D1\82\D0\B8_\D1\87\D0\B8_\D1\8E8_\D1\80\D1\96\D0\B2\D0\BD\D1\96"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca i1, align 1
  %"\D0\B0" = alloca ptr, align 8
  %"\D0\B1" = alloca ptr, align 8
  %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B0", align 8
  store ptr %1, ptr %"\D0\B1", align 8
  store i64 0, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  br label %while_cond

return:                                           ; preds = %while_body_exit, %while_body_exit, %if_body
  %load48 = load i1, ptr %return1, align 1
  ret i1 %load48

while_cond:                                       ; preds = %if_body_exit, %entry
  %load49 = load ptr, ptr %"\D0\B0", align 8
  %load50 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst = getelementptr i8, ptr %load49, i64 %load50
  %load51 = load i8, ptr %inst, align 1
  %load52 = load ptr, ptr %"\D0\B1", align 8
  %load53 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst2 = getelementptr i8, ptr %load52, i64 %load53
  %load54 = load i8, ptr %inst2, align 1
  %inst3 = icmp eq i8 %load51, %load54
  br i1 %inst3, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load55 = load ptr, ptr %"\D0\B0", align 8
  %load56 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst4 = getelementptr i8, ptr %load55, i64 %load56
  %load57 = load i8, ptr %inst4, align 1
  %inst5 = icmp eq i8 %load57, 0
  br i1 %inst5, label %if_body, label %if_body_else

while_body_exit:                                  ; preds = %while_cond
  store i1 false, ptr %return1, align 1
  br label %return
  br label %return

if_body:                                          ; preds = %while_body
  store i1 true, ptr %return1, align 1
  br label %return
  br label %if_body_exit

if_body_else:                                     ; preds = %while_body
  br label %if_body_exit

if_body_exit:                                     ; preds = %if_body_else, %if_body
  %load58 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst6 = add i64 %load58, 1
  store i64 %inst6, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  br label %while_cond
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BA\D0\BE\D0\BF\D1\96\D1\8E_\D1\8E8"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\B2\D0\B8\D1\85\D1\96\D0\B4\D0\BD\D0\B0" = alloca ptr, align 8
  %"\D0\B4\D0\BE\D0\B2\D0\B6\D0\B8\D0\BD\D0\B0" = alloca i64, align 8
  %"\D0\BA\D0\BE\D0\BF\D1\96\D1\8F" = alloca ptr, align 8
  %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B2\D0\B8\D1\85\D1\96\D0\B4\D0\BD\D0\B0", align 8
  store i64 0, ptr %"\D0\B4\D0\BE\D0\B2\D0\B6\D0\B8\D0\BD\D0\B0", align 4
  br label %while_cond

return:                                           ; preds = %while_body_exit11, %while_body_exit11
  %load59 = load ptr, ptr %return1, align 8
  ret ptr %load59

while_cond:                                       ; preds = %while_body, %entry
  %load60 = load ptr, ptr %"\D0\B2\D0\B8\D1\85\D1\96\D0\B4\D0\BD\D0\B0", align 8
  %load61 = load i64, ptr %"\D0\B4\D0\BE\D0\B2\D0\B6\D0\B8\D0\BD\D0\B0", align 4
  %inst = getelementptr i8, ptr %load60, i64 %load61
  %load62 = load i8, ptr %inst, align 1
  %inst2 = icmp ne i8 %load62, 0
  br i1 %inst2, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load63 = load i64, ptr %"\D0\B4\D0\BE\D0\B2\D0\B6\D0\B8\D0\BD\D0\B0", align 4
  %inst3 = add i64 %load63, 1
  store i64 %inst3, ptr %"\D0\B4\D0\BE\D0\B2\D0\B6\D0\B8\D0\BD\D0\B0", align 4
  br label %while_cond

while_body_exit:                                  ; preds = %while_cond
  %load64 = load i64, ptr %"\D0\B4\D0\BE\D0\B2\D0\B6\D0\B8\D0\BD\D0\B0", align 4
  %inst4 = trunc i64 %load64 to i32
  %inst5 = add i32 %inst4, 1
  %inst6 = call ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.1"(i32 %inst5)
  store ptr %inst6, ptr %"\D0\BA\D0\BE\D0\BF\D1\96\D1\8F", align 8
  store i64 0, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  br label %while_cond7

while_cond7:                                      ; preds = %while_body10, %while_body_exit
  %load65 = load ptr, ptr %"\D0\B2\D0\B8\D1\85\D1\96\D0\B4\D0\BD\D0\B0", align 8
  %load66 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst8 = getelementptr i8, ptr %load65, i64 %load66
  %load67 = load i8, ptr %inst8, align 1
  %inst9 = icmp ne i8 %load67, 0
  br i1 %inst9, label %while_body10, label %while_body_exit11

while_body10:                                     ; preds = %while_cond7
  %load68 = load ptr, ptr %"\D0\B2\D0\B8\D1\85\D1\96\D0\B4\D0\BD\D0\B0", align 8
  %load69 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst12 = getelementptr i8, ptr %load68, i64 %load69
  %load70 = load ptr, ptr %"\D0\BA\D0\BE\D0\BF\D1\96\D1\8F", align 8
  %load71 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst13 = getelementptr i8, ptr %load70, i64 %load71
  %load72 = load i8, ptr %inst12, align 1
  store i8 %load72, ptr %inst13, align 1
  %load73 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst14 = add i64 %load73, 1
  store i64 %inst14, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  br label %while_cond7

while_body_exit11:                                ; preds = %while_cond7
  %load74 = load ptr, ptr %"\D0\BA\D0\BE\D0\BF\D1\96\D1\8F", align 8
  %load75 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst15 = getelementptr i8, ptr %load74, i64 %load75
  store i8 0, ptr %inst15, align 1
  %load76 = load ptr, ptr %"\D0\BA\D0\BE\D0\BF\D1\96\D1\8F", align 8
  store ptr %load76, ptr %return1, align 8
  br label %return
  br label %return
}

define internal ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BA\D0\BE\D0\B4"() {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\BA\D0\BE\D0\B4" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  %inst = call ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.2"()
  store ptr %inst, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %load81 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst2 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load81, i32 0, i32 0
  store i32 0, ptr %inst2, align 4
  %load82 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst3 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load82, i32 0, i32 1
  store ptr null, ptr %inst3, align 8
  %load83 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst4 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load83, i32 0, i32 2
  store i32 0, ptr %inst4, align 4
  %load84 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst5 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load84, i32 0, i32 3
  store ptr null, ptr %inst5, align 8
  %load85 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst6 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load85, i32 0, i32 4
  store i32 0, ptr %inst6, align 4
  %load86 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst7 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load86, i32 0, i32 5
  store ptr null, ptr %inst7, align 8
  %load87 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst8 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load87, i32 0, i32 6
  store i32 0, ptr %inst8, align 4
  %load88 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst9 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load88, i32 0, i32 7
  store ptr null, ptr %inst9, align 8
  %load89 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst10 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load89, i32 0, i32 8
  store i32 0, ptr %inst10, align 4
  %load90 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst11 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load90, i32 0, i32 9
  store ptr null, ptr %inst11, align 8
  %load91 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst12 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load91, i32 0, i32 10
  store i32 0, ptr %inst12, align 4
  %load92 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst13 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load92, i32 0, i32 11
  store ptr null, ptr %inst13, align 8
  %load93 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  store ptr %load93, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load77 = load ptr, ptr %return1, align 8
  ret ptr %load77
}

define internal i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\BD\D0\B0\D0\B7\D0\B2\D1\83_\D0\B4\D0\BE_\D0\BA\D0\BE\D0\B4\D1\83"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca i32, align 4
  %"\D0\BA\D0\BE\D0\B4" = alloca ptr, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  store ptr %1, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load98 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load98, i32 0, i32 3
  %load99 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst2 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load99, i32 0, i32 2
  %load100 = load i32, ptr %inst2, align 4
  %inst3 = add i32 %load100, 1
  %load101 = load ptr, ptr %inst, align 8
  %inst4 = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8"(ptr %load101, i32 %inst3)
  %load102 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst5 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load102, i32 0, i32 3
  store ptr %inst4, ptr %inst5, align 8
  %load103 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst6 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load103, i32 0, i32 3
  %load104 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst7 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load104, i32 0, i32 2
  %load105 = load ptr, ptr %inst6, align 8
  %load106 = load i32, ptr %inst7, align 4
  %inst8 = getelementptr ptr, ptr %load105, i32 %load106
  %load107 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  store ptr %load107, ptr %inst8, align 8
  %load108 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst9 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load108, i32 0, i32 2
  %load109 = load i32, ptr %inst9, align 4
  %inst10 = add i32 %load109, 1
  %load110 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst11 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load110, i32 0, i32 2
  store i32 %inst10, ptr %inst11, align 4
  %load111 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst12 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load111, i32 0, i32 2
  %load112 = load i32, ptr %inst12, align 4
  %inst13 = sub i32 %load112, 1
  store i32 %inst13, ptr %return1, align 4
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load94 = load i32, ptr %return1, align 4
  ret i32 %load94
}

define internal i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D1\87\D0\B8\D1\81\D0\BB\D0\BE_\D0\B4\D0\BE_\D0\BA\D0\BE\D0\B4\D1\83"(ptr %0, double %1) {
alloca:
  %return1 = alloca i32, align 4
  %"\D0\BA\D0\BE\D0\B4" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca double, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  store double %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load117 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load117, i32 0, i32 5
  %load118 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst2 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load118, i32 0, i32 4
  %load119 = load i32, ptr %inst2, align 4
  %inst3 = add i32 %load119, 1
  %load120 = load ptr, ptr %inst, align 8
  %inst4 = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.4"(ptr %load120, i32 %inst3)
  %load121 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst5 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load121, i32 0, i32 5
  store ptr %inst4, ptr %inst5, align 8
  %load122 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst6 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load122, i32 0, i32 5
  %load123 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst7 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load123, i32 0, i32 4
  %load124 = load ptr, ptr %inst6, align 8
  %load125 = load i32, ptr %inst7, align 4
  %inst8 = getelementptr double, ptr %load124, i32 %load125
  %load126 = load double, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store double %load126, ptr %inst8, align 8
  %load127 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst9 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load127, i32 0, i32 4
  %load128 = load i32, ptr %inst9, align 4
  %inst10 = add i32 %load128, 1
  %load129 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst11 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load129, i32 0, i32 4
  store i32 %inst10, ptr %inst11, align 4
  %load130 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst12 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load130, i32 0, i32 4
  %load131 = load i32, ptr %inst12, align 4
  %inst13 = sub i32 %load131, 1
  store i32 %inst13, ptr %return1, align 4
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load113 = load i32, ptr %return1, align 4
  ret i32 %load113
}

define internal i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D1\82\D0\B5\D0\BA\D1\81\D1\82_\D0\B4\D0\BE_\D0\BA\D0\BE\D0\B4\D1\83"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca i32, align 4
  %"\D0\BA\D0\BE\D0\B4" = alloca ptr, align 8
  %"\D1\82\D0\B5\D0\BA\D1\81\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  store ptr %1, ptr %"\D1\82\D0\B5\D0\BA\D1\81\D1\82", align 8
  %load136 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load136, i32 0, i32 7
  %load137 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst2 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load137, i32 0, i32 6
  %load138 = load i32, ptr %inst2, align 4
  %inst3 = add i32 %load138, 1
  %load139 = load ptr, ptr %inst, align 8
  %inst4 = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.5"(ptr %load139, i32 %inst3)
  %load140 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst5 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load140, i32 0, i32 7
  store ptr %inst4, ptr %inst5, align 8
  %load141 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst6 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load141, i32 0, i32 7
  %load142 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst7 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load142, i32 0, i32 6
  %load143 = load ptr, ptr %inst6, align 8
  %load144 = load i32, ptr %inst7, align 4
  %inst8 = getelementptr ptr, ptr %load143, i32 %load144
  %load145 = load ptr, ptr %"\D1\82\D0\B5\D0\BA\D1\81\D1\82", align 8
  store ptr %load145, ptr %inst8, align 8
  %load146 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst9 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load146, i32 0, i32 6
  %load147 = load i32, ptr %inst9, align 4
  %inst10 = add i32 %load147, 1
  %load148 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst11 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load148, i32 0, i32 6
  store i32 %inst10, ptr %inst11, align 4
  %load149 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst12 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load149, i32 0, i32 6
  %load150 = load i32, ptr %inst12, align 4
  %inst13 = sub i32 %load150, 1
  store i32 %inst13, ptr %return1, align 4
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load132 = load i32, ptr %return1, align 4
  ret i32 %load132
}

define internal i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4_\D0\B4\D0\BE_\D0\BA\D0\BE\D0\B4\D1\83"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca i32, align 4
  %"\D0\BA\D0\BE\D0\B4" = alloca ptr, align 8
  %"\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  store ptr %1, ptr %"\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4", align 8
  %load152 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load152, i32 0, i32 9
  %load153 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst2 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load153, i32 0, i32 8
  %load154 = load i32, ptr %inst2, align 4
  %inst3 = add i32 %load154, 1
  %load155 = load ptr, ptr %inst, align 8
  %inst4 = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.5"(ptr %load155, i32 %inst3)
  %load156 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst5 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load156, i32 0, i32 9
  store ptr %inst4, ptr %inst5, align 8
  %load157 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst6 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load157, i32 0, i32 9
  %load158 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst7 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load158, i32 0, i32 8
  %load159 = load ptr, ptr %inst6, align 8
  %load160 = load i32, ptr %inst7, align 4
  %inst8 = getelementptr ptr, ptr %load159, i32 %load160
  %load161 = load ptr, ptr %"\D1\8E\D0\BD\D1\96\D0\BA\D0\BE\D0\B4", align 8
  store ptr %load161, ptr %inst8, align 8
  %load162 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst9 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load162, i32 0, i32 8
  %load163 = load i32, ptr %inst9, align 4
  %inst10 = add i32 %load163, 1
  %load164 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst11 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load164, i32 0, i32 8
  store i32 %inst10, ptr %inst11, align 4
  %load165 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst12 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load165, i32 0, i32 8
  %load166 = load i32, ptr %inst12, align 4
  %inst13 = sub i32 %load166, 1
  store i32 %inst13, ptr %return1, align 4
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load151 = load i32, ptr %return1, align 4
  ret i32 %load151
}

define internal i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D1\83_\D0\B4\D0\BE_\D0\BA\D0\BE\D0\B4\D1\83"(ptr %0, i8 %1) {
alloca:
  %return1 = alloca i32, align 4
  %"\D0\BA\D0\BE\D0\B4" = alloca ptr, align 8
  %"\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B0" = alloca i8, align 1
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  store i8 %1, ptr %"\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B0", align 1
  %load171 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load171, i32 0, i32 1
  %load172 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst2 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load172, i32 0, i32 0
  %load173 = load i32, ptr %inst2, align 4
  %inst3 = add i32 %load173, 1
  %load174 = load ptr, ptr %inst, align 8
  %inst4 = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.6"(ptr %load174, i32 %inst3)
  %load175 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst5 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load175, i32 0, i32 1
  store ptr %inst4, ptr %inst5, align 8
  %load176 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst6 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load176, i32 0, i32 1
  %load177 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst7 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load177, i32 0, i32 0
  %load178 = load ptr, ptr %inst6, align 8
  %load179 = load i32, ptr %inst7, align 4
  %inst8 = getelementptr i8, ptr %load178, i32 %load179
  %load180 = load i8, ptr %"\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B0", align 1
  store i8 %load180, ptr %inst8, align 1
  %load181 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst9 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load181, i32 0, i32 0
  %load182 = load i32, ptr %inst9, align 4
  %inst10 = add i32 %load182, 1
  %load183 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst11 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load183, i32 0, i32 0
  store i32 %inst10, ptr %inst11, align 4
  %load184 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst12 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load184, i32 0, i32 0
  %load185 = load i32, ptr %inst12, align 4
  %inst13 = sub i32 %load185, 1
  store i32 %inst13, ptr %return1, align 4
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load167 = load i32, ptr %return1, align 4
  ret i32 %load167
}

define internal i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D1\83_\D0\B4\D0\BE_\D0\BA\D0\BE\D0\B4\D1\83_\D0\B7_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\BE\D0\BC_\D0\BF32"(ptr %0, i8 %1, i32 %2) {
alloca:
  %return1 = alloca i32, align 4
  %"\D0\BA\D0\BE\D0\B4" = alloca ptr, align 8
  %"\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B0" = alloca i8, align 1
  %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  store i8 %1, ptr %"\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B0", align 1
  store i32 %2, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 4
  %load187 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load187, i32 0, i32 1
  %load188 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst2 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load188, i32 0, i32 0
  %load189 = load i32, ptr %inst2, align 4
  %inst3 = add i32 %load189, 1
  %inst4 = add i32 %inst3, 4
  %load190 = load ptr, ptr %inst, align 8
  %inst5 = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.6"(ptr %load190, i32 %inst4)
  %load191 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst6 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load191, i32 0, i32 1
  store ptr %inst5, ptr %inst6, align 8
  %load192 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst7 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load192, i32 0, i32 1
  %load193 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst8 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load193, i32 0, i32 0
  %load194 = load ptr, ptr %inst7, align 8
  %load195 = load i32, ptr %inst8, align 4
  %inst9 = getelementptr i8, ptr %load194, i32 %load195
  %load196 = load i8, ptr %"\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B0", align 1
  store i8 %load196, ptr %inst9, align 1
  %load197 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst10 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load197, i32 0, i32 1
  %load198 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst11 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load198, i32 0, i32 0
  %load199 = load i32, ptr %inst11, align 4
  %inst12 = add i32 %load199, 1
  %load200 = load i32, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 4
  %inst13 = and i32 %load200, 255
  %inst14 = trunc i32 %inst13 to i8
  %load201 = load ptr, ptr %inst10, align 8
  %inst15 = getelementptr i8, ptr %load201, i32 %inst12
  store i8 %inst14, ptr %inst15, align 1
  %load202 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst16 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load202, i32 0, i32 1
  %load203 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst17 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load203, i32 0, i32 0
  %load204 = load i32, ptr %inst17, align 4
  %inst18 = add i32 %load204, 2
  %load205 = load i32, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 4
  %inst19 = lshr i32 %load205, 8
  %inst20 = and i32 %inst19, 255
  %inst21 = trunc i32 %inst20 to i8
  %load206 = load ptr, ptr %inst16, align 8
  %inst22 = getelementptr i8, ptr %load206, i32 %inst18
  store i8 %inst21, ptr %inst22, align 1
  %load207 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst23 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load207, i32 0, i32 1
  %load208 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst24 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load208, i32 0, i32 0
  %load209 = load i32, ptr %inst24, align 4
  %inst25 = add i32 %load209, 3
  %load210 = load i32, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 4
  %inst26 = lshr i32 %load210, 16
  %inst27 = and i32 %inst26, 255
  %inst28 = trunc i32 %inst27 to i8
  %load211 = load ptr, ptr %inst23, align 8
  %inst29 = getelementptr i8, ptr %load211, i32 %inst25
  store i8 %inst28, ptr %inst29, align 1
  %load212 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst30 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load212, i32 0, i32 1
  %load213 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst31 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load213, i32 0, i32 0
  %load214 = load i32, ptr %inst31, align 4
  %inst32 = add i32 %load214, 4
  %load215 = load i32, ptr %"\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82", align 4
  %inst33 = lshr i32 %load215, 24
  %inst34 = and i32 %inst33, 255
  %inst35 = trunc i32 %inst34 to i8
  %load216 = load ptr, ptr %inst30, align 8
  %inst36 = getelementptr i8, ptr %load216, i32 %inst32
  store i8 %inst35, ptr %inst36, align 1
  %load217 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst37 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load217, i32 0, i32 0
  %load218 = load i32, ptr %inst37, align 4
  %inst38 = add i32 %load218, 1
  %inst39 = add i32 %inst38, 4
  %load219 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst40 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load219, i32 0, i32 0
  store i32 %inst39, ptr %inst40, align 4
  %load220 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst41 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load220, i32 0, i32 0
  %load221 = load i32, ptr %inst41, align 4
  %inst42 = sub i32 %load221, 1
  %inst43 = sub i32 %inst42, 4
  store i32 %inst43, ptr %return1, align 4
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load186 = load i32, ptr %return1, align 4
  ret i32 %load186
}

define internal i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\BF\D1\80\D0\BE\D1\87\D0\B8\D1\82\D0\B0\D1\82\D0\B8_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B8_\D0\BF32"(ptr %0, i32 %1) {
alloca:
  %return1 = alloca i32, align 4
  %"\D0\BA\D0\BE\D0\B4" = alloca ptr, align 8
  %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  store i32 %1, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %load223 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load223, i32 0, i32 1
  %load224 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst2 = add i32 %load224, 1
  %load225 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst3 = add i32 %load225, 1
  %load226 = load ptr, ptr %inst, align 8
  %inst4 = getelementptr i8, ptr %load226, i32 %inst2
  %load227 = load i8, ptr %inst4, align 1
  %inst5 = zext i8 %load227 to i32
  %load228 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst6 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load228, i32 0, i32 1
  %load229 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst7 = add i32 %load229, 2
  %load230 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst8 = add i32 %load230, 2
  %load231 = load ptr, ptr %inst6, align 8
  %inst9 = getelementptr i8, ptr %load231, i32 %inst7
  %load232 = load i8, ptr %inst9, align 1
  %inst10 = zext i8 %load232 to i32
  %inst11 = shl i32 %inst10, 8
  %inst12 = add i32 %inst5, %inst11
  %load233 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst13 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load233, i32 0, i32 1
  %load234 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst14 = add i32 %load234, 3
  %load235 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst15 = add i32 %load235, 3
  %load236 = load ptr, ptr %inst13, align 8
  %inst16 = getelementptr i8, ptr %load236, i32 %inst14
  %load237 = load i8, ptr %inst16, align 1
  %inst17 = zext i8 %load237 to i32
  %inst18 = shl i32 %inst17, 16
  %inst19 = add i32 %inst12, %inst18
  %load238 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst20 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load238, i32 0, i32 1
  %load239 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst21 = add i32 %load239, 4
  %load240 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst22 = add i32 %load240, 4
  %load241 = load ptr, ptr %inst20, align 8
  %inst23 = getelementptr i8, ptr %load241, i32 %inst21
  %load242 = load i8, ptr %inst23, align 1
  %inst24 = zext i8 %load242 to i32
  %inst25 = shl i32 %inst24, 24
  %inst26 = add i32 %inst19, %inst25
  store i32 %inst26, ptr %return1, align 4
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load222 = load i32, ptr %return1, align 4
  ret i32 %load222
}

define internal ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BD\D0\B0\D0\B7\D0\B2\D1\83"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst = call ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.7"()
  store ptr %inst, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load247 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BA\D0\BE\D0\BF\D1\96\D1\8E_\D1\8E8"(ptr %load247)
  %load248 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %inst3 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9D\D0\B0\D0\B7\D0\B2\D0\B0", ptr %load248, i32 0, i32 0
  store ptr %inst2, ptr %inst3, align 8
  %load249 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  store ptr %load249, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load243 = load ptr, ptr %return1, align 8
  ret ptr %load243
}

define internal i1 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D1\96\D1\80\D0\B8\D1\82\D0\B8_\D1\87\D0\B8_\D0\BD\D0\B0\D0\B7\D0\B2\D0\B8_\D1\80\D1\96\D0\B2\D0\BD\D1\96"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca i1, align 1
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B01" = alloca ptr, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B02" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B01", align 8
  store ptr %1, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B02", align 8
  %load251 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B01", align 8
  %load252 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B02", align 8
  %inst = icmp eq ptr %load251, %load252
  store i1 %inst, ptr %return1, align 1
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load250 = load i1, ptr %return1, align 1
  ret i1 %load250
}

define internal ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\9C" = alloca ptr, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D1\82\D1\80\D1\83\D0\BA\D1\82\D1\83\D1\80\D0\B8" = alloca ptr, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\9C", align 8
  store ptr %1, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D1\82\D1\80\D1\83\D0\BA\D1\82\D1\83\D1\80\D0\B8", align 8
  %inst = call ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.9"()
  store ptr %inst, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %load257 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %inst2 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load257, i32 0, i32 0
  store ptr null, ptr %inst2, align 8
  %inst3 = call %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0" @"\D0\B7\D1\80\D0\BE\D0\B1\D0\B8\D1\82\D0\B8_\D0\BA\D0\B0\D1\80\D1\82\D1\83"(ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D1\96\D1\80\D0\B8\D1\82\D0\B8_\D1\87\D0\B8_\D0\BD\D0\B0\D0\B7\D0\B2\D0\B8_\D1\80\D1\96\D0\B2\D0\BD\D1\96")
  %load262 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %inst4 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load262, i32 0, i32 1
  store %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0" %inst3, ptr %inst4, align 8
  %load263 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  %inst5 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load263, i32 0, i32 2
  store double 0.000000e+00, ptr %inst5, align 8
  %load264 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82", align 8
  store ptr %load264, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load253 = load ptr, ptr %return1, align 8
  ret ptr %load253
}

define internal ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0"(ptr %0, double %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\9C" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca double, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\9C", align 8
  store double %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %load307 = load ptr, ptr %"\D0\9C", align 8
  %inst = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load307, i32 0, i32 4
  %load308 = load ptr, ptr %"\D0\9C", align 8
  %load309 = load ptr, ptr %inst, align 8
  %inst2 = call ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load308, ptr %load309)
  store ptr %inst2, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0", align 8
  %load310 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0", align 8
  %inst3 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load310, i32 0, i32 2
  %load311 = load double, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store double %load311, ptr %inst3, align 8
  %load312 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0", align 8
  store ptr %load312, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load306 = load ptr, ptr %return1, align 8
  ret ptr %load306
}

define internal %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2" @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B7\D1\80\D0\BE\D0\B1\D0\B8\D1\82\D0\B8_\D0\B1\D0\B0\D0\B7\D1\83_\D0\BD\D0\B0\D0\B7\D0\B2"() {
alloca:
  %return1 = alloca %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", align 8
  %construct = alloca %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", align 8
  %"\D0\91\D0\9D" = alloca %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", align 8
  br label %entry

entry:                                            ; preds = %alloca
  %load417 = load %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %construct, align 8
  store %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2" %load417, ptr %"\D0\91\D0\9D", align 8
  %inst = call %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80" @"\D0\B7\D1\80\D0\BE\D0\B1\D0\B8\D1\82\D0\B8_\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80"()
  %inst2 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %"\D0\91\D0\9D", i32 0, i32 0
  store %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80" %inst, ptr %inst2, align 8
  %inst3 = call ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B7\D0\BD\D0\B0\D0\B9\D1\82\D0\B8_\D0\B0\D0\B1\D0\BE_\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\B9_\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\BD\D0\B0\D0\B7\D0\B2\D1\83"(ptr %"\D0\91\D0\9D", ptr @0)
  %inst4 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %"\D0\91\D0\9D", i32 0, i32 1
  store ptr %inst3, ptr %inst4, align 8
  %load421 = load %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %"\D0\91\D0\9D", align 8
  store %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2" %load421, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load416 = load %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %return1, align 8
  ret %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2" %load416
}

define internal ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B7\D0\BD\D0\B0\D0\B9\D1\82\D0\B8_\D0\B0\D0\B1\D0\BE_\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\B9_\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\BD\D0\B0\D0\B7\D0\B2\D1\83"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\91\D0\9D" = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F" = alloca i64, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0" = alloca ptr, align 8
  %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B011" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\91\D0\9D", align 8
  store ptr %1, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store i64 0, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  br label %while_cond

return:                                           ; preds = %while_body_exit, %while_body_exit, %if_body
  %load422 = load ptr, ptr %return1, align 8
  ret ptr %load422

while_cond:                                       ; preds = %if_body_exit, %entry
  %load423 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %load424 = load ptr, ptr %"\D0\91\D0\9D", align 8
  %inst = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %load424, i32 0, i32 0
  %inst2 = getelementptr %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %inst, i32 0, i32 0
  %load425 = load i64, ptr %inst2, align 4
  %inst3 = icmp ult i64 %load423, %load425
  br i1 %inst3, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load426 = load ptr, ptr %"\D0\91\D0\9D", align 8
  %inst4 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %load426, i32 0, i32 0
  %inst5 = getelementptr %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %inst4, i32 0, i32 1
  %load427 = load ptr, ptr %inst5, align 8
  %load428 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst6 = getelementptr ptr, ptr %load427, i64 %load428
  %load429 = load ptr, ptr %inst6, align 8
  store ptr %load429, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %load430 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  %inst7 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9D\D0\B0\D0\B7\D0\B2\D0\B0", ptr %load430, i32 0, i32 0
  %load431 = load ptr, ptr %inst7, align 8
  %load432 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst8 = call i1 @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D1\96\D1\80\D0\B8\D1\82\D0\B8_\D1\87\D0\B8_\D1\8E8_\D1\80\D1\96\D0\B2\D0\BD\D1\96"(ptr %load431, ptr %load432)
  br i1 %inst8, label %if_body, label %if_body_else

while_body_exit:                                  ; preds = %while_cond
  %load435 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst10 = call ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BD\D0\B0\D0\B7\D0\B2\D1\83"(ptr %load435)
  store ptr %inst10, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B011", align 8
  %load449 = load ptr, ptr %"\D0\91\D0\9D", align 8
  %inst12 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %load449, i32 0, i32 0
  %load450 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B011", align 8
  call void @"\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\B4\D0\BE_\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80\D1\83"(ptr %inst12, ptr %load450)
  %load451 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B011", align 8
  store ptr %load451, ptr %return1, align 8
  br label %return
  br label %return

if_body:                                          ; preds = %while_body
  %load433 = load ptr, ptr %"\D0\BD\D0\B0\D0\B7\D0\B2\D0\B0", align 8
  store ptr %load433, ptr %return1, align 8
  br label %return
  br label %if_body_exit

if_body_else:                                     ; preds = %while_body
  br label %if_body_exit

if_body_exit:                                     ; preds = %if_body_else, %if_body
  %load434 = load i64, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  %inst9 = add i64 %load434, 1
  store i64 %inst9, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F", align 4
  br label %while_cond
}

define internal ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BC\D0\B0\D1\88\D0\B8\D0\BD\D1\83"() {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\9C" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  %inst = call ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.12"()
  store ptr %inst, ptr %"\D0\9C", align 8
  %inst2 = call %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2" @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B7\D1\80\D0\BE\D0\B1\D0\B8\D1\82\D0\B8_\D0\B1\D0\B0\D0\B7\D1\83_\D0\BD\D0\B0\D0\B7\D0\B2"()
  %load317 = load ptr, ptr %"\D0\9C", align 8
  %inst3 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load317, i32 0, i32 0
  store %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2" %inst2, ptr %inst3, align 8
  %inst4 = call %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0" @"\D0\B7\D1\80\D0\BE\D0\B1\D0\B8\D1\82\D0\B8_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D1\83"()
  %load321 = load ptr, ptr %"\D0\9C", align 8
  %inst5 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load321, i32 0, i32 1
  store %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0" %inst4, ptr %inst5, align 8
  %load322 = load ptr, ptr %"\D0\9C", align 8
  %inst6 = call ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load322, ptr null)
  %load323 = load ptr, ptr %"\D0\9C", align 8
  %inst7 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load323, i32 0, i32 2
  store ptr %inst6, ptr %inst7, align 8
  %load324 = load ptr, ptr %"\D0\9C", align 8
  %inst8 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load324, i32 0, i32 2
  %load325 = load ptr, ptr %inst8, align 8
  %inst9 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load325, i32 0, i32 1
  call void @"\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B8\D1\82\D0\B8_\D0\BA\D0\B0\D1\80\D1\82\D1\83"(ptr %inst9, i64 1)
  %load326 = load ptr, ptr %"\D0\9C", align 8
  %inst10 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load326, i32 0, i32 2
  %load327 = load ptr, ptr %inst10, align 8
  %inst11 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load327, i32 0, i32 1
  %inst12 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %inst11, i32 0, i32 1
  %load328 = load ptr, ptr %inst12, align 8
  %inst13 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %load328, i32 0
  %load329 = load ptr, ptr %"\D0\9C", align 8
  %inst14 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load329, i32 0, i32 0
  %inst15 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %inst14, i32 0, i32 1
  %inst16 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %inst13, i32 0, i32 0
  %load330 = load ptr, ptr %inst15, align 8
  store ptr %load330, ptr %inst16, align 8
  %load331 = load ptr, ptr %"\D0\9C", align 8
  %inst17 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load331, i32 0, i32 2
  %load332 = load ptr, ptr %inst17, align 8
  %inst18 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load332, i32 0, i32 1
  %inst19 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %inst18, i32 0, i32 1
  %load333 = load ptr, ptr %inst19, align 8
  %inst20 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %load333, i32 0
  %inst21 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %inst20, i32 0, i32 1
  store ptr null, ptr %inst21, align 8
  %load334 = load ptr, ptr %"\D0\9C", align 8
  %inst22 = call ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load334, ptr null)
  %load335 = load ptr, ptr %"\D0\9C", align 8
  %inst23 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load335, i32 0, i32 3
  store ptr %inst22, ptr %inst23, align 8
  %load336 = load ptr, ptr %"\D0\9C", align 8
  %inst24 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load336, i32 0, i32 3
  %load337 = load ptr, ptr %"\D0\9C", align 8
  %inst25 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load337, i32 0, i32 3
  %load338 = load ptr, ptr %inst24, align 8
  %inst26 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load338, i32 0, i32 0
  %load339 = load ptr, ptr %inst25, align 8
  store ptr %load339, ptr %inst26, align 8
  %load340 = load ptr, ptr %"\D0\9C", align 8
  %inst27 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load340, i32 0, i32 3
  %load341 = load ptr, ptr %inst27, align 8
  %inst28 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load341, i32 0, i32 1
  call void @"\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B8\D1\82\D0\B8_\D0\BA\D0\B0\D1\80\D1\82\D1\83"(ptr %inst28, i64 1)
  %load342 = load ptr, ptr %"\D0\9C", align 8
  %inst29 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load342, i32 0, i32 3
  %load343 = load ptr, ptr %inst29, align 8
  %inst30 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load343, i32 0, i32 1
  %inst31 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %inst30, i32 0, i32 1
  %load344 = load ptr, ptr %inst31, align 8
  %inst32 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %load344, i32 0
  %load345 = load ptr, ptr %"\D0\9C", align 8
  %inst33 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load345, i32 0, i32 0
  %inst34 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %inst33, i32 0, i32 1
  %inst35 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %inst32, i32 0, i32 0
  %load346 = load ptr, ptr %inst34, align 8
  store ptr %load346, ptr %inst35, align 8
  %load347 = load ptr, ptr %"\D0\9C", align 8
  %inst36 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load347, i32 0, i32 3
  %load348 = load ptr, ptr %inst36, align 8
  %inst37 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load348, i32 0, i32 1
  %inst38 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %inst37, i32 0, i32 1
  %load349 = load ptr, ptr %inst38, align 8
  %inst39 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %load349, i32 0
  %load350 = load ptr, ptr %"\D0\9C", align 8
  %inst40 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load350, i32 0, i32 2
  %inst41 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %inst39, i32 0, i32 1
  %load351 = load ptr, ptr %inst40, align 8
  store ptr %load351, ptr %inst41, align 8
  %load352 = load ptr, ptr %"\D0\9C", align 8
  %inst42 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load352, i32 0, i32 2
  %load353 = load ptr, ptr %"\D0\9C", align 8
  %inst43 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load353, i32 0, i32 3
  %load354 = load ptr, ptr %inst42, align 8
  %inst44 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load354, i32 0, i32 0
  %load355 = load ptr, ptr %inst43, align 8
  store ptr %load355, ptr %inst44, align 8
  %load356 = load ptr, ptr %"\D0\9C", align 8
  %inst45 = call ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D1\82\D1\80\D1\83\D0\BA\D1\82\D1\83\D1\80\D0\B8"(ptr %load356, ptr null)
  %load357 = load ptr, ptr %"\D0\9C", align 8
  %inst46 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load357, i32 0, i32 4
  store ptr %inst45, ptr %inst46, align 8
  %load358 = load ptr, ptr %"\D0\9C", align 8
  store ptr %load358, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load313 = load ptr, ptr %return1, align 8
  ret ptr %load313
}

define internal void @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\BA\D0\BE\D0\BD\D0\B0\D1\82\D0\B8_\D0\BA\D0\BE\D0\B4"(ptr %0, ptr %1) {
alloca:
  %"\D0\9C" = alloca ptr, align 8
  %"\D0\BA\D0\BE\D0\B4" = alloca ptr, align 8
  %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B8" = alloca i32, align 4
  %"\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B0" = alloca i8, align 1
  %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D1\87\D0\B8\D1\81\D0\BB\D0\B0" = alloca i32, align 4
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B02" = alloca ptr, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B01" = alloca ptr, align 8
  %"\D1\87\D0\B8\D1\81\D0\BB\D0\BE1" = alloca double, align 8
  %"\D1\87\D0\B8\D1\81\D0\BB\D0\BE2" = alloca double, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\9C", align 8
  store ptr %1, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  store i32 0, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B8", align 4
  br label %while_cond

return:                                           ; preds = %while_body_exit
  ret void

while_cond:                                       ; preds = %if_body_exit, %entry
  %load359 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B8", align 4
  %load360 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load360, i32 0, i32 0
  %load361 = load i32, ptr %inst, align 4
  %inst1 = icmp ult i32 %load359, %load361
  br i1 %inst1, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load362 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst2 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load362, i32 0, i32 1
  %load363 = load ptr, ptr %inst2, align 8
  %load364 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B8", align 4
  %inst3 = getelementptr i8, ptr %load363, i32 %load364
  %load365 = load i8, ptr %inst3, align 1
  store i8 %load365, ptr %"\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B0", align 1
  %load366 = load i8, ptr %"\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B0", align 1
  %inst4 = icmp eq i8 %load366, 6
  br i1 %inst4, label %if_body, label %if_body_else

while_body_exit:                                  ; preds = %while_cond
  br label %return

if_body:                                          ; preds = %while_body
  %load367 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %load368 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B8", align 4
  %inst5 = call i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\BF\D1\80\D0\BE\D1\87\D0\B8\D1\82\D0\B0\D1\82\D0\B8_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B8_\D0\BF32"(ptr %load367, i32 %load368)
  store i32 %inst5, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D1\87\D0\B8\D1\81\D0\BB\D0\B0", align 4
  %load369 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B8", align 4
  %inst6 = add i32 %load369, 4
  store i32 %inst6, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B8", align 4
  %load386 = load ptr, ptr %"\D0\9C", align 8
  %inst7 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load386, i32 0, i32 1
  %load387 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst8 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9A\D0\BE\D0\B4", ptr %load387, i32 0, i32 5
  %load388 = load ptr, ptr %inst8, align 8
  %load389 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D1\87\D0\B8\D1\81\D0\BB\D0\B0", align 4
  %inst9 = getelementptr double, ptr %load388, i32 %load389
  %load390 = load ptr, ptr %"\D0\9C", align 8
  %load391 = load double, ptr %inst9, align 8
  %inst10 = call ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0"(ptr %load390, double %load391)
  call void @"\D0\BF\D0\BE\D0\BA\D0\BB\D0\B0\D1\81\D1\82\D0\B8_\D0\BD\D0\B0_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D1\83"(ptr %inst7, ptr %inst10)
  br label %if_body_exit

if_body_else:                                     ; preds = %while_body
  %load392 = load i8, ptr %"\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B0", align 1
  %inst11 = icmp eq i8 %load392, 13
  br i1 %inst11, label %if_body12, label %if_body_else13

if_body_exit:                                     ; preds = %if_body_exit14, %if_body
  %load415 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B8", align 4
  %inst24 = add i32 %load415, 1
  store i32 %inst24, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D0\B8", align 4
  br label %while_cond

if_body12:                                        ; preds = %if_body_else
  %load405 = load ptr, ptr %"\D0\9C", align 8
  %inst15 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load405, i32 0, i32 1
  %inst16 = call ptr @"\D0\B7\D0\B0\D0\B1\D1\80\D0\B0\D1\82\D0\B8_\D0\B7_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B8"(ptr %inst15)
  store ptr %inst16, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B02", align 8
  %load406 = load ptr, ptr %"\D0\9C", align 8
  %inst17 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load406, i32 0, i32 1
  %inst18 = call ptr @"\D0\B7\D0\B0\D0\B1\D1\80\D0\B0\D1\82\D0\B8_\D0\B7_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B8"(ptr %inst17)
  store ptr %inst18, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B01", align 8
  %load407 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B01", align 8
  %inst19 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load407, i32 0, i32 2
  %load408 = load double, ptr %inst19, align 8
  store double %load408, ptr %"\D1\87\D0\B8\D1\81\D0\BB\D0\BE1", align 8
  %load409 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B02", align 8
  %inst20 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load409, i32 0, i32 2
  %load410 = load double, ptr %inst20, align 8
  store double %load410, ptr %"\D1\87\D0\B8\D1\81\D0\BB\D0\BE2", align 8
  %load411 = load ptr, ptr %"\D0\9C", align 8
  %inst21 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load411, i32 0, i32 1
  %load412 = load double, ptr %"\D1\87\D0\B8\D1\81\D0\BB\D0\BE1", align 8
  %load413 = load double, ptr %"\D1\87\D0\B8\D1\81\D0\BB\D0\BE2", align 8
  %inst22 = fadd double %load412, %load413
  %load414 = load ptr, ptr %"\D0\9C", align 8
  %inst23 = call ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\87\D0\B8\D1\81\D0\BB\D0\B0"(ptr %load414, double %inst22)
  call void @"\D0\BF\D0\BE\D0\BA\D0\BB\D0\B0\D1\81\D1\82\D0\B8_\D0\BD\D0\B0_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D1\83"(ptr %inst21, ptr %inst23)
  br label %if_body_exit14

if_body_else13:                                   ; preds = %if_body_else
  br label %if_body_exit14

if_body_exit14:                                   ; preds = %if_body_else13, %if_body12
  br label %if_body_exit
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.2"() {
alloca:
  %return1 = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  %inst = call ptr @mavka_ext_malloc(i32 96)
  store ptr %inst, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load78 = load ptr, ptr %return1, align 8
  ret ptr %load78
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.3"(i32 %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load80 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %inst = mul i32 %load80, 96
  %inst2 = call ptr @mavka_ext_malloc(i32 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load79 = load ptr, ptr %return1, align 8
  ret ptr %load79
}

define internal ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8"(ptr %0, i32 %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store i32 %1, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load96 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %inst = mul i32 %load96, 8
  %load97 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr @mavka_ext_realloc(ptr %load97, i32 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load95 = load ptr, ptr %return1, align 8
  ret ptr %load95
}

define internal ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.4"(ptr %0, i32 %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store i32 %1, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load115 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %inst = mul i32 %load115, 8
  %load116 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr @mavka_ext_realloc(ptr %load116, i32 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load114 = load ptr, ptr %return1, align 8
  ret ptr %load114
}

define internal ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.5"(ptr %0, i32 %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store i32 %1, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load134 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %inst = mul i32 %load134, 8
  %load135 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr @mavka_ext_realloc(ptr %load135, i32 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load133 = load ptr, ptr %return1, align 8
  ret ptr %load133
}

define internal ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.6"(ptr %0, i32 %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store i32 %1, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load169 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %inst = mul i32 %load169, 1
  %load170 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr @mavka_ext_realloc(ptr %load170, i32 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load168 = load ptr, ptr %return1, align 8
  ret ptr %load168
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.7"() {
alloca:
  %return1 = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  %inst = call ptr @mavka_ext_malloc(i32 8)
  store ptr %inst, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load244 = load ptr, ptr %return1, align 8
  ret ptr %load244
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.8"(i32 %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load246 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %inst = mul i32 %load246, 8
  %inst2 = call ptr @mavka_ext_malloc(i32 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load245 = load ptr, ptr %return1, align 8
  ret ptr %load245
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.9"() {
alloca:
  %return1 = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  %inst = call ptr @mavka_ext_malloc(i32 48)
  store ptr %inst, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load254 = load ptr, ptr %return1, align 8
  ret ptr %load254
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.10"(i32 %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load256 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %inst = mul i32 %load256, 48
  %inst2 = call ptr @mavka_ext_malloc(i32 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load255 = load ptr, ptr %return1, align 8
  ret ptr %load255
}

define internal %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0" @"\D0\B7\D1\80\D0\BE\D0\B1\D0\B8\D1\82\D0\B8_\D0\BA\D0\B0\D1\80\D1\82\D1\83"(ptr %0) {
alloca:
  %return1 = alloca %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", align 8
  %"\D0\B4\D1\96\D1\8F_\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D1\96\D1\80\D0\BA\D0\B8_\D0\BA\D0\BB\D1\8E\D1\87\D0\B0" = alloca ptr, align 8
  %construct = alloca %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", align 8
  %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0" = alloca %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B4\D1\96\D1\8F_\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D1\96\D1\80\D0\BA\D0\B8_\D0\BA\D0\BB\D1\8E\D1\87\D0\B0", align 8
  %load259 = load %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %construct, align 8
  store %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0" %load259, ptr %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0", align 8
  %inst = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0", i32 0, i32 0
  store i64 0, ptr %inst, align 4
  %inst2 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0", i32 0, i32 1
  store ptr null, ptr %inst2, align 8
  %inst3 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0", i32 0, i32 2
  %load260 = load ptr, ptr %"\D0\B4\D1\96\D1\8F_\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D1\96\D1\80\D0\BA\D0\B8_\D0\BA\D0\BB\D1\8E\D1\87\D0\B0", align 8
  store ptr %load260, ptr %inst3, align 8
  %load261 = load %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0", align 8
  store %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0" %load261, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load258 = load %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %return1, align 8
  ret %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0" %load258
}

define internal ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D1\82\D1\80\D1\83\D0\BA\D1\82\D1\83\D1\80\D0\B8"(ptr %0, ptr %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\9C" = alloca ptr, align 8
  %"\D0\BF\D1\80\D0\B5\D0\B4\D0\BE\D0\BA" = alloca ptr, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D1\82\D1\80\D1\83\D0\BA\D1\82\D1\83\D1\80\D0\B8" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\9C", align 8
  store ptr %1, ptr %"\D0\BF\D1\80\D0\B5\D0\B4\D0\BE\D0\BA", align 8
  %load266 = load ptr, ptr %"\D0\9C", align 8
  %inst = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load266, i32 0, i32 3
  %load267 = load ptr, ptr %"\D0\9C", align 8
  %load268 = load ptr, ptr %inst, align 8
  %inst2 = call ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82"(ptr %load267, ptr %load268)
  store ptr %inst2, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D1\82\D1\80\D1\83\D0\BA\D1\82\D1\83\D1\80\D0\B8", align 8
  %load269 = load ptr, ptr %"\D0\BF\D1\80\D0\B5\D0\B4\D0\BE\D0\BA", align 8
  %inst3 = icmp eq ptr %load269, null
  br i1 %inst3, label %if_body, label %if_body_else

return:                                           ; preds = %if_body_exit, %if_body_exit
  %load265 = load ptr, ptr %return1, align 8
  ret ptr %load265

if_body:                                          ; preds = %entry
  %load282 = load ptr, ptr %"\D0\9C", align 8
  %inst4 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load282, i32 0, i32 3
  %load283 = load ptr, ptr %inst4, align 8
  %inst5 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load283, i32 0, i32 1
  call void @"\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B8\D1\82\D0\B8_\D0\BA\D0\B0\D1\80\D1\82\D1\83"(ptr %inst5, i64 1)
  %load284 = load ptr, ptr %"\D0\9C", align 8
  %inst6 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load284, i32 0, i32 3
  %load285 = load ptr, ptr %inst6, align 8
  %inst7 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load285, i32 0, i32 1
  %inst8 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %inst7, i32 0, i32 1
  %load286 = load ptr, ptr %inst8, align 8
  %inst9 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %load286, i32 0
  %load287 = load ptr, ptr %"\D0\9C", align 8
  %inst10 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load287, i32 0, i32 0
  %inst11 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %inst10, i32 0, i32 1
  %inst12 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %inst9, i32 0, i32 0
  %load288 = load ptr, ptr %inst11, align 8
  store ptr %load288, ptr %inst12, align 8
  %load289 = load ptr, ptr %"\D0\9C", align 8
  %inst13 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load289, i32 0, i32 3
  %load290 = load ptr, ptr %inst13, align 8
  %inst14 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load290, i32 0, i32 1
  %inst15 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %inst14, i32 0, i32 1
  %load291 = load ptr, ptr %inst15, align 8
  %inst16 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %load291, i32 0
  %load292 = load ptr, ptr %"\D0\9C", align 8
  %inst17 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load292, i32 0, i32 2
  %inst18 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %inst16, i32 0, i32 1
  %load293 = load ptr, ptr %inst17, align 8
  store ptr %load293, ptr %inst18, align 8
  br label %if_body_exit

if_body_else:                                     ; preds = %entry
  %load294 = load ptr, ptr %"\D0\9C", align 8
  %inst19 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load294, i32 0, i32 3
  %load295 = load ptr, ptr %inst19, align 8
  %inst20 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load295, i32 0, i32 1
  call void @"\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B8\D1\82\D0\B8_\D0\BA\D0\B0\D1\80\D1\82\D1\83"(ptr %inst20, i64 1)
  %load296 = load ptr, ptr %"\D0\9C", align 8
  %inst21 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load296, i32 0, i32 3
  %load297 = load ptr, ptr %inst21, align 8
  %inst22 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load297, i32 0, i32 1
  %inst23 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %inst22, i32 0, i32 1
  %load298 = load ptr, ptr %inst23, align 8
  %inst24 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %load298, i32 0
  %load299 = load ptr, ptr %"\D0\9C", align 8
  %inst25 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load299, i32 0, i32 0
  %inst26 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\91\D0\B0\D0\B7\D0\B0\D0\9D\D0\B0\D0\B7\D0\B2", ptr %inst25, i32 0, i32 1
  %inst27 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %inst24, i32 0, i32 0
  %load300 = load ptr, ptr %inst26, align 8
  store ptr %load300, ptr %inst27, align 8
  %load301 = load ptr, ptr %"\D0\9C", align 8
  %inst28 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load301, i32 0, i32 3
  %load302 = load ptr, ptr %inst28, align 8
  %inst29 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load302, i32 0, i32 1
  %inst30 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %inst29, i32 0, i32 1
  %load303 = load ptr, ptr %inst30, align 8
  %inst31 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %load303, i32 0
  %inst32 = getelementptr %"\D0\95\D0\BB\D0\B5\D0\BC\D0\B5\D0\BD\D1\82\D0\9A\D0\B0\D1\80\D1\82\D0\B8", ptr %inst31, i32 0, i32 1
  %load304 = load ptr, ptr %"\D0\BF\D1\80\D0\B5\D0\B4\D0\BE\D0\BA", align 8
  store ptr %load304, ptr %inst32, align 8
  br label %if_body_exit

if_body_exit:                                     ; preds = %if_body_else, %if_body
  %load305 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D1\81\D1\82\D1\80\D1\83\D0\BA\D1\82\D1\83\D1\80\D0\B8", align 8
  store ptr %load305, ptr %return1, align 8
  br label %return
  br label %return
}

define internal void @"\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B8\D1\82\D0\B8_\D0\BA\D0\B0\D1\80\D1\82\D1\83"(ptr %0, i64 %1) {
alloca:
  %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0" = alloca ptr, align 8
  %"\D0\BD\D0\BE\D0\B2\D0\B8\D0\B9_\D1\80\D0\BE\D0\B7\D0\BC\D1\96\D1\80" = alloca i64, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0", align 8
  store i64 %1, ptr %"\D0\BD\D0\BE\D0\B2\D0\B8\D0\B9_\D1\80\D0\BE\D0\B7\D0\BC\D1\96\D1\80", align 4
  %load270 = load i64, ptr %"\D0\BD\D0\BE\D0\B2\D0\B8\D0\B9_\D1\80\D0\BE\D0\B7\D0\BC\D1\96\D1\80", align 4
  %load271 = load ptr, ptr %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0", align 8
  %inst = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %load271, i32 0, i32 0
  %load272 = load i64, ptr %inst, align 4
  %inst1 = icmp ugt i64 %load270, %load272
  br i1 %inst1, label %if_body, label %if_body_else

return:                                           ; preds = %if_body_exit
  ret void

if_body:                                          ; preds = %entry
  %load276 = load ptr, ptr %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0", align 8
  %inst2 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %load276, i32 0, i32 1
  %load277 = load i64, ptr %"\D0\BD\D0\BE\D0\B2\D0\B8\D0\B9_\D1\80\D0\BE\D0\B7\D0\BC\D1\96\D1\80", align 4
  %inst3 = trunc i64 %load277 to i32
  %load278 = load ptr, ptr %inst2, align 8
  %inst4 = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.11"(ptr %load278, i32 %inst3)
  %load279 = load ptr, ptr %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0", align 8
  %inst5 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %load279, i32 0, i32 1
  store ptr %inst4, ptr %inst5, align 8
  %load280 = load ptr, ptr %"\D0\BA\D0\B0\D1\80\D1\82\D0\B0", align 8
  %inst6 = getelementptr %"\D0\9A\D0\B0\D1\80\D1\82\D0\B0", ptr %load280, i32 0, i32 0
  %load281 = load i64, ptr %"\D0\BD\D0\BE\D0\B2\D0\B8\D0\B9_\D1\80\D0\BE\D0\B7\D0\BC\D1\96\D1\80", align 4
  store i64 %load281, ptr %inst6, align 4
  br label %if_body_exit

if_body_else:                                     ; preds = %entry
  br label %if_body_exit

if_body_exit:                                     ; preds = %if_body_else, %if_body
  br label %return
}

define internal ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.11"(ptr %0, i32 %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store i32 %1, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load274 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %inst = mul i32 %load274, 16
  %load275 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr @mavka_ext_realloc(ptr %load275, i32 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load273 = load ptr, ptr %return1, align 8
  ret ptr %load273
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.12"() {
alloca:
  %return1 = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  %inst = call ptr @mavka_ext_malloc(i32 64)
  store ptr %inst, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load314 = load ptr, ptr %return1, align 8
  ret ptr %load314
}

define internal ptr @"\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.13"(i32 %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load316 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %inst = mul i32 %load316, 64
  %inst2 = call ptr @mavka_ext_malloc(i32 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load315 = load ptr, ptr %return1, align 8
  ret ptr %load315
}

define internal %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0" @"\D0\B7\D1\80\D0\BE\D0\B1\D0\B8\D1\82\D0\B8_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D1\83"() {
alloca:
  %return1 = alloca %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %construct = alloca %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0" = alloca %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  br label %entry

entry:                                            ; preds = %alloca
  %load319 = load %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %construct, align 8
  store %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0" %load319, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", i32 0, i32 0
  store i64 0, ptr %inst, align 4
  %inst2 = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", i32 0, i32 1
  store ptr null, ptr %inst2, align 8
  %load320 = load %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  store %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0" %load320, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load318 = load %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %return1, align 8
  ret %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0" %load318
}

define internal void @"\D0\BF\D0\BE\D0\BA\D0\BB\D0\B0\D1\81\D1\82\D0\B8_\D0\BD\D0\B0_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D1\83"(ptr %0, ptr %1) {
alloca:
  %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0" = alloca ptr, align 8
  %"\D0\B4\D0\B0\D0\BD\D1\96" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  store ptr %1, ptr %"\D0\B4\D0\B0\D0\BD\D1\96", align 8
  %load373 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load373, i32 0, i32 1
  %load374 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst1 = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load374, i32 0, i32 0
  %load375 = load i64, ptr %inst1, align 4
  %inst2 = add i64 %load375, 1
  %inst3 = trunc i64 %inst2 to i32
  %load376 = load ptr, ptr %inst, align 8
  %inst4 = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.14"(ptr %load376, i32 %inst3)
  %load377 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst5 = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load377, i32 0, i32 1
  store ptr %inst4, ptr %inst5, align 8
  %load378 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst6 = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load378, i32 0, i32 1
  %load379 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst7 = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load379, i32 0, i32 0
  %load380 = load ptr, ptr %inst6, align 8
  %load381 = load i64, ptr %inst7, align 4
  %inst8 = getelementptr ptr, ptr %load380, i64 %load381
  %load382 = load ptr, ptr %"\D0\B4\D0\B0\D0\BD\D1\96", align 8
  store ptr %load382, ptr %inst8, align 8
  %load383 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst9 = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load383, i32 0, i32 0
  %load384 = load i64, ptr %inst9, align 4
  %inst10 = add i64 %load384, 1
  %load385 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst11 = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load385, i32 0, i32 0
  store i64 %inst10, ptr %inst11, align 4
  br label %return

return:                                           ; preds = %entry
  ret void
}

define internal ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8.14"(ptr %0, i32 %1) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F" = alloca ptr, align 8
  %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C" = alloca i32, align 4
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  store i32 %1, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %load371 = load i32, ptr %"\D0\BA\D1\96\D0\BB\D1\8C\D0\BA\D1\96\D1\81\D1\82\D1\8C", align 4
  %inst = mul i32 %load371, 8
  %load372 = load ptr, ptr %"\D0\B7\D0\BD\D0\B0\D1\87\D0\B5\D0\BD\D0\BD\D1\8F", align 8
  %inst2 = call ptr @mavka_ext_realloc(ptr %load372, i32 %inst)
  store ptr %inst2, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load370 = load ptr, ptr %return1, align 8
  ret ptr %load370
}

define internal ptr @"\D0\B7\D0\B0\D0\B1\D1\80\D0\B0\D1\82\D0\B8_\D0\B7_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B8"(ptr %0) {
alloca:
  %return1 = alloca ptr, align 8
  %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0" = alloca ptr, align 8
  %"\D0\B4\D0\B0\D0\BD\D1\96" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %load394 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load394, i32 0, i32 1
  %load395 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst2 = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load395, i32 0, i32 0
  %load396 = load i64, ptr %inst2, align 4
  %inst3 = sub i64 %load396, 1
  %load397 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst4 = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load397, i32 0, i32 0
  %load398 = load i64, ptr %inst4, align 4
  %inst5 = sub i64 %load398, 1
  %load399 = load ptr, ptr %inst, align 8
  %inst6 = getelementptr ptr, ptr %load399, i64 %inst3
  %load400 = load ptr, ptr %inst6, align 8
  store ptr %load400, ptr %"\D0\B4\D0\B0\D0\BD\D1\96", align 8
  %load401 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst7 = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load401, i32 0, i32 0
  %load402 = load i64, ptr %inst7, align 4
  %inst8 = sub i64 %load402, 1
  %load403 = load ptr, ptr %"\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", align 8
  %inst9 = getelementptr %"\D0\A1\D1\82\D0\BE\D0\BF\D0\BA\D0\B0", ptr %load403, i32 0, i32 0
  store i64 %inst8, ptr %inst9, align 4
  %load404 = load ptr, ptr %"\D0\B4\D0\B0\D0\BD\D1\96", align 8
  store ptr %load404, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load393 = load ptr, ptr %return1, align 8
  ret ptr %load393
}

define internal %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80" @"\D0\B7\D1\80\D0\BE\D0\B1\D0\B8\D1\82\D0\B8_\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80"() {
alloca:
  %return1 = alloca %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  %construct = alloca %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80" = alloca %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  br label %entry

entry:                                            ; preds = %alloca
  %load419 = load %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %construct, align 8
  store %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80" %load419, ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  %inst = getelementptr %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", i32 0, i32 0
  store i64 0, ptr %inst, align 4
  %inst2 = getelementptr %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", i32 0, i32 1
  store ptr null, ptr %inst2, align 8
  %load420 = load %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  store %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80" %load420, ptr %return1, align 8
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load418 = load %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %return1, align 8
  ret %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80" %load418
}

define internal void @"\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\B4\D0\BE_\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80\D1\83"(ptr %0, ptr %1) {
alloca:
  %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80" = alloca ptr, align 8
  %"\D0\B4\D0\B0\D0\BD\D1\96" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store ptr %0, ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  store ptr %1, ptr %"\D0\B4\D0\B0\D0\BD\D1\96", align 8
  %load436 = load ptr, ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  %inst = getelementptr %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %load436, i32 0, i32 1
  %load437 = load ptr, ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  %inst1 = getelementptr %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %load437, i32 0, i32 0
  %load438 = load i64, ptr %inst1, align 4
  %inst2 = add i64 %load438, 1
  %inst3 = trunc i64 %inst2 to i32
  %load439 = load ptr, ptr %inst, align 8
  %inst4 = call ptr @"\D0\BF\D0\B5\D1\80\D0\B5\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8"(ptr %load439, i32 %inst3)
  %load440 = load ptr, ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  %inst5 = getelementptr %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %load440, i32 0, i32 1
  store ptr %inst4, ptr %inst5, align 8
  %load441 = load ptr, ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  %inst6 = getelementptr %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %load441, i32 0, i32 1
  %load442 = load ptr, ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  %inst7 = getelementptr %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %load442, i32 0, i32 0
  %load443 = load ptr, ptr %inst6, align 8
  %load444 = load i64, ptr %inst7, align 4
  %inst8 = getelementptr ptr, ptr %load443, i64 %load444
  %load445 = load ptr, ptr %"\D0\B4\D0\B0\D0\BD\D1\96", align 8
  store ptr %load445, ptr %inst8, align 8
  %load446 = load ptr, ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  %inst9 = getelementptr %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %load446, i32 0, i32 0
  %load447 = load i64, ptr %inst9, align 4
  %inst10 = add i64 %load447, 1
  %load448 = load ptr, ptr %"\D0\B2\D0\B5\D0\BA\D1\82\D0\BE\D1\80", align 8
  %inst11 = getelementptr %"\D0\92\D0\B5\D0\BA\D1\82\D0\BE\D1\80", ptr %load448, i32 0, i32 0
  store i64 %inst10, ptr %inst11, align 4
  br label %return

return:                                           ; preds = %entry
  ret void
}

define i32 @main(i32 %0, ptr %1) {
alloca:
  %return1 = alloca i32, align 4
  %args = alloca i32, align 4
  %argv = alloca ptr, align 8
  %"\D0\BA\D0\BE\D0\B4" = alloca ptr, align 8
  %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D1\87\D0\B8\D1\81\D0\BB\D0\B0" = alloca i32, align 4
  %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D1\87\D0\B8\D1\81\D0\BB\D0\B01" = alloca i32, align 4
  %"\D0\9C" = alloca ptr, align 8
  %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D1\96_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B8" = alloca ptr, align 8
  br label %entry

entry:                                            ; preds = %alloca
  store i32 %0, ptr %args, align 4
  store ptr %1, ptr %argv, align 8
  %inst = call ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BA\D0\BE\D0\B4"()
  store ptr %inst, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %load453 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst2 = call i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D1\87\D0\B8\D1\81\D0\BB\D0\BE_\D0\B4\D0\BE_\D0\BA\D0\BE\D0\B4\D1\83"(ptr %load453, double 1.000000e+01)
  store i32 %inst2, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D1\87\D0\B8\D1\81\D0\BB\D0\B0", align 4
  %load454 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst3 = call i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D1\87\D0\B8\D1\81\D0\BB\D0\BE_\D0\B4\D0\BE_\D0\BA\D0\BE\D0\B4\D1\83"(ptr %load454, double 2.000000e+01)
  store i32 %inst3, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D1\87\D0\B8\D1\81\D0\BB\D0\B01", align 4
  %load455 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %load456 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D1\87\D0\B8\D1\81\D0\BB\D0\B0", align 4
  %inst4 = call i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D1\83_\D0\B4\D0\BE_\D0\BA\D0\BE\D0\B4\D1\83_\D0\B7_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\BE\D0\BC_\D0\BF32"(ptr %load455, i8 6, i32 %load456)
  %load457 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %load458 = load i32, ptr %"\D0\BF\D0\BE\D0\B7\D0\B8\D1\86\D1\96\D1\8F_\D1\87\D0\B8\D1\81\D0\BB\D0\B01", align 4
  %inst5 = call i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D1\83_\D0\B4\D0\BE_\D0\BA\D0\BE\D0\B4\D1\83_\D0\B7_\D0\B0\D1\80\D0\B3\D1\83\D0\BC\D0\B5\D0\BD\D1\82\D0\BE\D0\BC_\D0\BF32"(ptr %load457, i8 6, i32 %load458)
  %load459 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  %inst6 = call i32 @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B4\D0\BE\D0\B4\D0\B0\D1\82\D0\B8_\D0\B2\D0\BA\D0\B0\D0\B7\D1\96\D0\B2\D0\BA\D1\83_\D0\B4\D0\BE_\D0\BA\D0\BE\D0\B4\D1\83"(ptr %load459, i8 13)
  %inst7 = call ptr @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\B4\D1\96\D0\BB\D0\B8\D1\82\D0\B8_\D0\BC\D0\B0\D1\88\D0\B8\D0\BD\D1\83"()
  store ptr %inst7, ptr %"\D0\9C", align 8
  %load460 = load ptr, ptr %"\D0\9C", align 8
  %load461 = load ptr, ptr %"\D0\BA\D0\BE\D0\B4", align 8
  call void @"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\B2\D0\B8\D0\BA\D0\BE\D0\BD\D0\B0\D1\82\D0\B8_\D0\BA\D0\BE\D0\B4"(ptr %load460, ptr %load461)
  %load462 = load ptr, ptr %"\D0\9C", align 8
  %inst8 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9C\D0\B0\D1\88\D0\B8\D0\BD\D0\B0", ptr %load462, i32 0, i32 1
  %inst9 = call ptr @"\D0\B7\D0\B0\D0\B1\D1\80\D0\B0\D1\82\D0\B8_\D0\B7_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B8"(ptr %inst8)
  store ptr %inst9, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D1\96_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B8", align 8
  %load463 = load ptr, ptr %"\D0\BE\D0\B1\CA\BC\D1\94\D0\BA\D1\82_\D0\B7\D1\96_\D1\81\D1\82\D0\BE\D0\BF\D0\BA\D0\B8", align 8
  %inst10 = getelementptr %"\D0\9C\D0\B0\D0\9C\D0\B0::\D0\9E\D0\B1\CA\BC\D1\94\D0\BA\D1\82", ptr %load463, i32 0, i32 2
  %load464 = load double, ptr %inst10, align 8
  call void @"\D0\BD\D0\B0\D0\B4\D1\80\D1\83\D0\BA\D1\83\D0\B2\D0\B0\D1\82\D0\B8_\D0\B464"(double %load464)
  store i32 0, ptr %return1, align 4
  br label %return
  br label %return

return:                                           ; preds = %entry, %entry
  %load452 = load i32, ptr %return1, align 4
  ret i32 %load452
}
