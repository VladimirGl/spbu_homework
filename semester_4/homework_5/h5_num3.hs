list_123 :: Int -> [[Int]]
list_123 n | n <= 0 = []
list_123 1 = [[1],[2],[3]]
list_123 n = do
	x <- [1, 2, 3]
	map (x:) (list_123 (n - 1))
