data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Show)

max_depth :: Tree a -> Int
max_depth Empty = 0
max_depth (Node lsub n rsub) = 1 + max (max_depth lsub) (max_depth rsub)

min_depth :: Tree a -> Int
min_depth Empty = 0
min_depth (Node Empty _ rsub) = 1 + min_depth(rsub)
min_depth (Node lsub _ Empty) = 1 + min_depth(lsub)
min_depth (Node lsub _ rsub) = 1 + min (min_depth lsub) (min_depth rsub)

from_list :: (Ord a) => [a] -> Tree a
from_list [] = Empty
from_list (x:xs) = Node (from_list (filter (<x) xs)) x (from_list (filter (>x) xs))
