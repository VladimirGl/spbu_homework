next :: Int -> Int
next 1 = 7
next 7 = 9
next 9 = 11
next x 
    | m == 9 = (next d) * 10 + 1
    | otherwise = d * 10 + next m 
  where
    m = mod x 10
    d = div x 10

list = 1 : map next list
