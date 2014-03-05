check_brackets :: [Char] -> Bool
check_brackets = check_brackets' 0 . filter(`elem` "()") 
  where  
    check_brackets' c [] = (c == 0)
    check_brackets' c (x:xs) 
        | (x == '(') = check_brackets' (c + 1) xs
        | (x == ')') = check_brackets' (c - 1) xs
