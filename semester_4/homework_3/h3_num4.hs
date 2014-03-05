import Data.List
import Data.Maybe

sum_list :: [Int] -> [Int]
sum_list l = zipWith (+) (0 : l) (l ++ [0])

first_max [] = error "the list is empty"
first_max [_] = error "only one element in the list"
first_max l = fromJust $ elemIndex (maximum $ sum_list l) (sum_list l)
