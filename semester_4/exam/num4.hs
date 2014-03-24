list_series xs = fst result / snd result
    where result = accum xs 0 1
             where accum [] sum prod = (sum, prod)
                   accum (x:xs) sum prod = accum xs (sum+x) (prod * (cos x))
