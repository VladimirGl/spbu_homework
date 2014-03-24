data Tree a = Empty | Node (Tree a) a (Tree a)
	deriving (Show)

	
to_list :: Tree a -> [a]
to_list = flatten []
    where flatten xs Empty = xs
          flatten xs (Node left x right) = flatten (x:(flatten xs right)) left


from_list :: (Ord a) => [a] -> Tree a
from_list [] = Empty
from_list (x:xs) = Node (from_list (filter (<x) xs)) x (from_list (filter (>x) xs))


negative_list :: (Num a, Ord a) => Tree a -> [a]
negative_list = filter (<0) . to_list

tree = from_list [1,2,-3,4,5,-6,7,-2,-7,12,33]
test = (length $ negative_list tree) == 4
