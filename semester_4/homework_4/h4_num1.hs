data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Show)
	
t_filter :: (a -> Bool) -> Tree a -> [a]
t_filter m_filter Empty = []
t_filter m_filter (Node lsub n rsub) = if m_filter n then filter_l ++ n : filter_r else filter_l ++ filter_r
    where
    filter_l = t_filter m_filter lsub
    filter_r = t_filter m_filter rsub
	
from_list :: (Ord a) => [a] -> Tree a
from_list [] = Empty
from_list (x:xs) = Node (from_list (filter (<x) xs)) x (from_list (filter (>x) xs))

test = (t_filter (\x -> x < 10) (from_list [1,5,2,3,22,17,66,13])) == [1,2,3,5]
