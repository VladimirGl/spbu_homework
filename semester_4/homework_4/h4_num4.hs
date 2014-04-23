is_unique :: Eq a => [a] -> Bool
is_unique [] = True
is_unique (x:xs) 
		| not (elem x xs) = is_unique xs
		| otherwise = False
