data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Eq, Show)
	
from_list :: (Ord a) => [a] -> Tree a
from_list [] = Empty
from_list (x:xs) = Node (from_list (filter (<x) xs)) x (from_list (filter (>x) xs))
	
to_list Empty = []
to_list(Node lsub n rsub) = n:(to_list lsub) ++ (to_list rsub)

t_foldl :: (a -> a -> a) -> a -> Tree a -> a
t_foldl f z Empty = z
t_foldl f z t = foldl f z (to_list t)

test = t_foldl (+) 0 (from_list [1,5,3,2,54,4,22])