factorial :: Integer -> Integer
factorial 0 = 1
factorial x = x * factorial (x - 1)

factorial' :: Integer -> Integer
factorial' 0 = 1
factorial' x = foldl (*) 1 [1..x]

factorials = 1 : scanl (*) 1 [2..]
