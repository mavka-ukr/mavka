; ModuleID = '/home/kohutd/CLionProjects/mavka-1.0.0/./непотріб/розширення_привіт.ц'
source_filename = "/home/kohutd/CLionProjects/mavka-1.0.0/./\D0\BD\D0\B5\D0\BF\D0\BE\D1\82\D1\80\D1\96\D0\B1/\D1\80\D0\BE\D0\B7\D1\88\D0\B8\D1\80\D0\B5\D0\BD\D0\BD\D1\8F_\D0\BF\D1\80\D0\B8\D0\B2\D1\96\D1\82.\D1\86"

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
  %load1 = load i8, ptr %"\D0\BF", align 1
  %inst = icmp slt i8 %load1, 127
  br i1 %inst, label %while_body, label %while_body_exit

while_body:                                       ; preds = %while_cond
  %load2 = load i8, ptr %"\D0\BF", align 1
  %inst1 = call i32 @putchar(i8 %load2)
  %load3 = load i8, ptr %"\D0\BF", align 1
  %inst2 = add i8 %load3, 1
  store i8 %inst2, ptr %"\D0\BF", align 1
  br label %while_cond

while_body_exit:                                  ; preds = %while_cond
  %inst3 = call i32 @putchar(i8 10)
  br label %return
}
