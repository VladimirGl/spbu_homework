import Data.List (sort)

equal_list a b = sort a == sort b

contains [] _ = False
contains (x:xs) a
  | equal_list x a = True
  | otherwise = contains xs a

unique [] = []
unique (x:xs)
  | contains xs x  = unique xs
  | otherwise = x : unique xs

dec :: Int -> [[Int]]
dec 1 = [[1]]
dec n = [n] : concatMap  (\x -> map (\l -> x:l) (dec $ n - x)) [1 .. (n - 1)]

-- по заданному числу n выводит все его разложения на положительные слагаемые (с точностью до порядка разложения)
dec_unique :: Int -> [[Int]]
dec_unique = unique . dec
