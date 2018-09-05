; ModuleID = 'getelementptr2.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %size = alloca i32, align 4
  %A = alloca double*, align 8
  %B = alloca double*, align 8
  %C = alloca i32*, align 8
  %i = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 10, i32* %size, align 4
  store i32 0, i32* %i, align 4
  br label %2

; <label>:2                                       ; preds = %20, %0
  %3 = load i32, i32* %i, align 4
  %4 = load i32, i32* %size, align 4
  %5 = icmp slt i32 %3, %4
  br i1 %5, label %6, label %23

; <label>:6                                       ; preds = %2
  %7 = load i32, i32* %i, align 4
  %8 = sext i32 %7 to i64
  %9 = load i32*, i32** %C, align 8
  %10 = getelementptr inbounds i32, i32* %9, i64 %8
  %11 = load i32, i32* %10, align 4
  %12 = sext i32 %11 to i64
  %13 = load double*, double** %B, align 8
  %14 = getelementptr inbounds double, double* %13, i64 %12
  %15 = load double, double* %14, align 8
  %16 = load i32, i32* %i, align 4
  %17 = sext i32 %16 to i64
  %18 = load double*, double** %A, align 8
  %19 = getelementptr inbounds double, double* %18, i64 %17
  store double %15, double* %19, align 8
  br label %20

; <label>:20                                      ; preds = %6
  %21 = load i32, i32* %i, align 4
  %22 = add nsw i32 %21, 1
  store i32 %22, i32* %i, align 4
  br label %2

; <label>:23                                      ; preds = %2
  %24 = load i32, i32* %1, align 4
  ret i32 %24
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1 (tags/RELEASE_381/final 340800) (llvm/tags/RELEASE_381/final 340799)"}
