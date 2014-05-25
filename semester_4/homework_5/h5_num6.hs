data Polynom a =  Var |
                  Const a | 
                  Pow (Polynom a) Int |
                  Add (Polynom a) (Polynom a) |
                  Sub (Polynom a) (Polynom a) |
                  Mul (Polynom a) (Polynom a) |
                  Div (Polynom a) (Polynom a)
						  
derivate (Var) = (Const 1)
derivate (Const a) = (Const 0)
derivate (Pow Var 1) = (Const 1)
derivate (Pow Var n) = Mul (Const n) (Pow (Var) (n - 1))
derivate (Pow p n) = Mul (Const (n - 1)) (Mul (Pow p (n - 1)) (derivate p))
derivate (Add p q) = Add (derivate p) (derivate q)
derivate (Sub p q) = Sub (derivate p) (derivate q)
derivate (Mul p q) = Add (Mul (derivate p) q) (Mul p (derivate q)) 
derivate (Div p q) = Div (Sub (Mul (derivate p) q) (Mul p (derivate q))) (Pow q 2)


simpl (Add p (Const 0)) = p
simpl (Add (Const 0) p) = p
simpl (Sub p (Const 0)) = p
simpl (Sub (Const 0) p) = Mul (Const (-1)) p
simpl (Mul (Const 0) p) = Const 0
simpl (Mul p (Const 0)) = Const 0
simpl (Mul (Const 1) p) = p
simpl (Mul p (Const 1)) = p
simpl (Mul (Const a) (Const b)) = Const (a * b)
simpl (Div p (Const 1)) = p
simpl (Div (Const 0) p) = (Const 0)
simpl (Pow (Const 0) _) = (Const 0)
simpl (Pow _ 0) = (Const 1)
simpl (Pow p 1) = p
simpl (Pow (Const 1) _) = (Const 1)
simpl p = p

simpl_polynom (Add p q) = simpl (Add (simpl_polynom p) (simpl_polynom q))
simpl_polynom (Sub p q) = simpl (Sub (simpl_polynom p) (simpl_polynom q))
simpl_polynom (Mul p q) = simpl (Mul (simpl_polynom p) (simpl_polynom q))
simpl_polynom (Div p q) = simpl (Div (simpl_polynom p) (simpl_polynom q))
simpl_polynom (Pow p n) = simpl (Pow (simpl_polynom p) n)
simpl_polynom p = p

instance Show a => Show (Polynom a) where
             show (Const a) = show a
             show (Var) = "x"
             show (Add p q) = "(" ++ show p ++ "+" ++ show q ++ ")"
             show (Sub p q) = "(" ++ show p ++ "-" ++ show q ++ ")"
             show (Mul p q) = "(" ++ show p ++ "*" ++ show q ++ ")"
             show (Div p q) = "(" ++ show p ++ "/" ++ show q ++ ")"
             show (Pow p n) = "(" ++ show p ++ ")^" ++ show n

der = simpl_polynom . derivate

main = do
   let polynom = Pow (Sub (Pow (Var) 2) (Const 1)) (3)
   putStrLn (show $ der polynom)