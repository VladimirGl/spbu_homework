is_even :: Int -> Bool
is_even x = (x `mod` 2 == 0)

-- filter
even_count_1 :: [Int] -> Int
even_count_1 = length . (filter $ is_even)

-- map
even_count_2 :: [Int] -> Int
even_count_2 = sum . map (\x -> if is_even x then 1 else 0)


-- foldr
even_count_3 :: [Int] -> Int
even_count_3 = foldr (+) 0 . map (\x -> if is_even x then 1 else 0)
