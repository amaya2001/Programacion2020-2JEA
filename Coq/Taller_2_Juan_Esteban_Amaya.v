(* LINDO TALLER 2*)

(* Punto 1*)
Inductive ConecLog: Type := (* Conectores logicos *)
  | O: ConecLog
  | Y: ConecLog
  | E: ConecLog
  | DE: ConecLog.

Inductive Proposicion: Set := (* Variables proposicionales y estrutura de la formula *)
  | P: Proposicion
  | Q: Proposicion
  | R: Proposicion
  | NEG: Proposicion -> Proposicion
  | LP: Proposicion -> ConecLog -> Proposicion ->Proposicion.

Definition FormP := LP  P  O ( NEG ( LP ( NEG P ) E ( P ) ) ).
Compute FormP.

(* Punto 2 *)
(* Una formula de logica de proposicional, contiene subconjuntos que corresponden 
a formulas proposicionales. Por esta razon Propsicion esta definido como un conjunto. *)
(* El caso base son las variables proposicionales, y el caso inductivo es la 
descomposición de la formula LP hasta llegar al caso base, que corresponde a una variable 
proposicional *)


(* Punto 3 *)
Fixpoint NumConec( F: Proposicion ): nat := (* Devuelve el numero de conectivos binarios *)
  match F with
    | P => 0
    | Q => 0
    | R => 0
    | NEG F => NumConec F
    | LP F1 C F2 =>( NumConec F1 + NumConec F2 ) + 1
  end.
Compute NumConec FormP.

(* Punto 4 *)
Fixpoint Profundidad( F: Proposicion ): nat := (* Devuelve la profundidad de una formula *)
  match F with
    | P => 1
    | Q => 1
    | R => 1
    | NEG F1 => ( Profundidad F1 ) + 1
    | LP F1 C F2 => Nat.max ( Profundidad F1 + 1 )( Profundidad F2 + 1 ) (* Nat.max -> Reibe dos parametros y retorna el valor maximo entre ellos *)
  end.
Compute Profundidad FormP.

(* Punto 5 *)
Fixpoint pVeces ( F: Proposicion ):nat := (* Devuelve la cantidad de veces que aparece la letra proposicional P *)
  match F with
    | P => 1
    | NEG F => pVeces F
    | LP F1 C F2 => pVeces F1 + pVeces F2
    |_ => 0 
  end.
Compute pVeces FormP.

(* //////////////////////////// CADENAS ////////////////////////////// *)

(* Punto 1 *)
Inductive CADENA: Set := (* Definición del tipo cadena, donde cada elemento es un natural *)
  | STRING : nat -> CADENA
  | CONCATENAR : CADENA -> CADENA -> CADENA.

Definition Cadena1 := STRING.
Definition Cadena2 := CONCATENAR ( STRING 3 )( STRING 2 ). 

Compute Cadena1.
Compute Cadena2.

(* Punto 2 *)
Fixpoint EsVacio( F: CADENA ):bool := (* Retorna si una cadena esta vacia *)
  match F with
    | STRING F1 => false
    | CONCATENAR F1 F2 => EsVacio F1 || EsVacio F2
  end.
Compute EsVacio Cadena2.

(* Punto 3 *)
Fixpoint Longitud( F: CADENA ):nat := (* Retorna la longitud de la cadena *)
  match F with
    | STRING F1 => 1  
    | CONCATENAR F1 F2 => ( Longitud F1 + Longitud F2 )
  end.
Compute Longitud Cadena2.

(* Punto 4 *)
Fixpoint SumaValor( F: CADENA ):nat := (* Retorna la suma de cada valor natural de una cadena *)
  match F with
    | STRING F1 =>   F1  
    | CONCATENAR F1 F2 => ( SumaValor F1 + SumaValor F2 )
  end.
Compute SumaValor Cadena2.

(* Punto 5 *)
Fixpoint Invertir( F: CADENA ):CADENA := (* Invierte los valores de la cadena *)
  match F with 
    | STRING F1 => STRING F1
    | CONCATENAR F1 F2 => CONCATENAR ( Invertir F2 ) ( Invertir F1 ) 
  end.
Compute Invertir Cadena2.