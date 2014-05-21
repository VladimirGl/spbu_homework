local_max :: [Int] -> Maybe Int
local_max [_] = Nothing
local_max [_,_] = Nothing
local_max (x:y:z:xs) = return xs >>= \ys -> if (x < y) && (y > z) then Just y else local_max (y:z:ys) 
