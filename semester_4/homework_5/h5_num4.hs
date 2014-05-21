pairwise_prod_list :: Int -> [Int]
pairwise_prod_list 1 = [1]
pairwise_prod_list n = [1..n] >>= (\x -> map(x*) [1..n])
