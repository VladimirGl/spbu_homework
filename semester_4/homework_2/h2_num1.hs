list_reverse :: [a] -> [a]
list_reverse l = _list_reverse l []
    where
        _list_reverse :: [a] -> [a] -> [a]
        _list_reverse [] l = l
        _list_reverse (x:xs) l = _list_reverse xs (x:l)
