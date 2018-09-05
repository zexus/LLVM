; ModuleID = 'getelementptr1.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.ST = type { i32, double, %struct.RT }
%struct.RT = type { i8, [10 x [20 x i32]], i8 }

; Function Attrs: nounwind uwtable
define i32* @foo(%struct.ST* %s) #0 {
  %1 = alloca %struct.ST*, align 8
  store %struct.ST* %s, %struct.ST** %1, align 8
  %2 = load %struct.ST*, %struct.ST** %1, align 8
  %3 = getelementptr inbounds %struct.ST, %struct.ST* %2, i64 1
  %4 = getelementptr inbounds %struct.ST, %struct.ST* %3, i32 0, i32 2
  %5 = getelementptr inbounds %struct.RT, %struct.RT* %4, i32 0, i32 1
  %6 = getelementptr inbounds [10 x [20 x i32]], [10 x [20 x i32]]* %5, i64 0, i64 5
  %7 = getelementptr inbounds [20 x i32], [20 x i32]* %6, i64 0, i64 13
  ret i32* %7
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1 (tags/RELEASE_381/final 340800) (llvm/tags/RELEASE_381/final 340799)"}
