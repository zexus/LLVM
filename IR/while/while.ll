; ModuleID = 'while.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %1, align 4
  br label %2

; <label>:2                                       ; preds = %5, %0
  %3 = load i32, i32* %i, align 4
  %4 = icmp slt i32 %3, 10
  br i1 %4, label %5, label %10

; <label>:5                                       ; preds = %2
  %6 = load i32, i32* %i, align 4
  %7 = add nsw i32 %6, 1
  store i32 %7, i32* %i, align 4
  %8 = load i32, i32* %a, align 4
  %9 = mul nsw i32 %8, 2
  store i32 %9, i32* %a, align 4
  br label %2

; <label>:10                                      ; preds = %2
  %11 = load i32, i32* %1, align 4
  ret i32 %11
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1 (tags/RELEASE_381/final 340800) (llvm/tags/RELEASE_381/final 340799)"}
