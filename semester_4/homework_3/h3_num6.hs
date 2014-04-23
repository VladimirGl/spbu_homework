is_pair :: Char -> Char -> Bool
is_pair '(' ')' = True
is_pair '[' ']' = True
is_pair '{' '}' = True
is_pair _ _ = False

is_open :: Char -> Bool
is_open ch = (ch == '(') || (ch == '[') || (ch == '{')

is_close :: Char -> Bool
is_close ch = (ch == ')') || (ch == ']') || (ch == '}')

brackets :: [Char] -> [Char] -> Bool
brackets [] [] = True
brackets [] _ = False
brackets (x : xs) l
                    | is_open x = brackets xs (x : l)          
                    | is_close x = if ((l /= []) && is_pair (head l) x) then brackets xs (tail l)
                        else False
                    | otherwise = brackets xs l

is_correct_brackets :: [Char] -> Bool
is_correct_brackets s = brackets s []