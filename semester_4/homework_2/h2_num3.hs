digits_list :: Integer -> [Integer]
digits_list 0 = []
digits_list n = digits_list (n `div` 10) ++ [n `mod` 10]

sum_of_digits :: Integer -> Integer
sum_of_digits = sum . digits_list


sum_of_digits' :: Integer -> Integer
sum_of_digits' 0 = 0
sum_of_digits' n = sum_of_digits' (n `div` 10) + (n `mod` 10)
