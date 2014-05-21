
is_condition :: [a] -> (a -> Bool) -> Bool
is_condition xs cond = (length xs) == (length $ filter cond xs)
