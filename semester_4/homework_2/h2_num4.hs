first_instance :: Integer -> [Integer] -> Integer
first_instance _ [] = error "Value not instance"
first_instance n (x:xs) 
        | n == x = 1
        | otherwise = (first_instance n xs) + 1
