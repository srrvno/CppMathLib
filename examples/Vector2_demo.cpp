# include <iostream>
# include <MathLib/Vector2.hpp>

using std::cout;
using std::endl;

void spc(int n=1) {
    for (int i = 0; i < n; i++) {
        cout << endl;
    }
}

int main()
{
    // ============================================================
    // 1. CONSTRUCTORES
    // ============================================================

    cout << "===== CONSTRUCTORS =====" << endl;

    Vector2 v0;            // constructor vacio
    Vector2 v1(3, 4);      // constructor normal
    Vector2 v2{1, 2};      // initializer_list

    cout << "v0 = ";
    v0.print();

    cout << "v1 = ";
    v1.print();

    cout << "v2 = ";
    v2.print();

    spc();


    // ============================================================
    // 2. ACCESO A COMPONENTES
    // ============================================================

    cout << "===== COMPONENT ACCESS =====" << endl;

    cout << "v1.x = " << v1.x << endl;
    cout << "v1.y = " << v1.y << endl;

    cout << "v1[0] = " << v1[0] << endl;
    cout << "v1[1] = " << v1[1] << endl;

    // Como operator[] devuelve double&, podemos modificar el
    // componente real del vector:
    v1[0] = 10;

    cout << "After v1[0] = 10:" << endl;
    v1.print();

    spc();


    // ============================================================
    // 3. COPY CONSTRUCTOR / COPY ASSIGNMENT
    // ============================================================

    cout << "===== COPY =====" << endl;

    Vector2 copy1(v2);       // copy constructor
    Vector2 copy2;
    copy2 = v2;              // copy assignment

    cout << "Original: ";
    v2.print();

    cout << "Copy constructor: ";
    copy1.print();

    cout << "Copy assignment: ";
    copy2.print();

    spc();


    // ============================================================
    // 4. SUMA
    // ============================================================

    cout << "===== ADDITION =====" << endl;

    Vector2 a{1, 2};
    Vector2 b{3, 4};

    cout << "a = ";
    a.print();

    cout << "b = ";
    b.print();

    Vector2 sum = a + b;

    cout << "a + b = ";
    sum.print();

    // a no cambia con +
    cout << "a is still: ";
    a.print();

    a += b;

    // += SI modifica a
    cout << "After a += b:" << endl;
    a.print();

    spc();


    // ============================================================
    // 5. RESTA
    // ============================================================

    cout << "===== SUBTRACTION =====" << endl;

    Vector2 c{8, 5};
    Vector2 d{3, 2};

    cout << "c - d = ";
    (c - d).print();

    c -= d;

    cout << "After c -= d:" << endl;
    c.print();

    spc();


    // ============================================================
    // 6. OPERACIONES CON ESCALARES
    // ============================================================

    cout << "===== SCALAR OPERATIONS =====" << endl;

    Vector2 e{2, 3};

    cout << "e = ";
    e.print();

    cout << "e * 2 = ";
    (e * 2).print();

    cout << "e / 2 = ";
    (e / 2).print();

    cout << "e + 5 = ";
    (e + 5).print();

    cout << "e - 1 = ";
    (e - 1).print();

    spc();


    // ============================================================
    // 7. OPERACIONES COMPONENTE A COMPONENTE
    // ============================================================

    cout << "===== COMPONENT-WISE OPERATIONS =====" << endl;

    Vector2 f{2, 6};
    Vector2 g{3, 2};

    cout << "f * g = ";
    (f * g).print();

    cout << "f / g = ";
    (f / g).print();

    // OJO:
    // esto NO es dot product.
    //
    // {2,6} * {3,2}
    //      =
    // {2*3, 6*2}
    //      =
    // {6,12}

    spc();


    // ============================================================
    // 8. LENGTH
    // ============================================================

    cout << "===== LENGTH =====" << endl;

    Vector2 h{3, 4};

    /*
        Geometricamente:

            y
            ^
          4 |       h(3,4)
            |      /
            |     /
            |    /  length = 5
            |   /
            |  /
            | /
            +-------------> x
               3

        Por Pitagoras:

        length = sqrt(3^2 + 4^2)
               = 5
    */

    cout << "h = ";
    h.print();

    cout << "length = " << h.length() << endl;
    cout << "length squared = " << h.length2() << endl;

    spc();


    // ============================================================
    // 9. NORMALIZACION
    // ============================================================

    cout << "===== NORMALIZATION =====" << endl;

    Vector2 n{3, 4};

    Vector2 normalizedCopy = n.normalized();

    cout << "Original n:" << endl;
    n.print();

    cout << "n.normalized():" << endl;
    normalizedCopy.print();

    cout << "Its length should be 1:" << endl;
    cout << normalizedCopy.length() << endl;

    // normalized() NO modifica n:
    cout << "Original n is still:" << endl;
    n.print();

    // normalize() SI modifica n:
    n.normalize();

    cout << "After n.normalize():" << endl;
    n.print();

    cout << "Length now = " << n.length() << endl;

    spc();


    // ============================================================
    // 10. DISTANCIA
    // ============================================================

    cout << "===== DISTANCE =====" << endl;

    Vector2 p1{1, 1};
    Vector2 p2{4, 5};

    /*
          p2(4,5)
             *
            /|
           / |
          /  | 4
         /   |
        *----+
      p1    3

      distancia = sqrt(3^2 + 4^2) = 5
    */

    cout << "p1 = ";
    p1.print();

    cout << "p2 = ";
    p2.print();

    cout << "distance = " << p1.distance(p2) << endl;
    cout << "distance squared = " << p1.distance2(p2) << endl;

    spc();


    // ============================================================
    // 11. DOT PRODUCT
    // ============================================================

    cout << "===== DOT PRODUCT =====" << endl;

    /*
        El dot product nos dice, de forma muy resumida,
        cuanto apunta un vector en la direccion del otro.

        a · b = |a||b|cos(theta)


        CASO 1: MISMA DIRECCION

        a ------>
        b ------>

        dot > 0
    */

    Vector2 right1{1, 0};
    Vector2 right2{5, 0};

    cout << "Same direction:" << endl;
    cout << right1.dot(right2) << endl;


    /*
        CASO 2: PERPENDICULARES

              b
              ^
              |
              |
        ------+------> a

        theta = 90 deg
        cos(90) = 0

        dot = 0
    */

    Vector2 right{1, 0};
    Vector2 up{0, 1};

    cout << "Perpendicular:" << endl;
    cout << right.dot(up) << endl;


    /*
        CASO 3: DIRECCIONES OPUESTAS

        b <------  ------> a

        theta = 180 deg
        cos(180) = -1

        dot < 0
    */

    Vector2 left{-1, 0};

    cout << "Opposite direction:" << endl;
    cout << right.dot(left) << endl;

    spc();


    // ============================================================
    // 12. CROSS PRODUCT 2D
    // ============================================================

    cout << "===== CROSS PRODUCT 2D =====" << endl;

    /*
        En Vector2 el cross NO devuelve otro vector.

        Devuelve:

            ax * by - ay * bx

        que equivale a la componente Z que tendria el
        producto vectorial si ambos vectores estuvieran
        dentro del plano XY.


        CASO 1:

              b
              ^
              |
              |
              +------> a

        Para ir desde a hasta b hay que girar
        en sentido antihorario.

        a.cross(b) > 0
    */

    Vector2 crossA{1, 0};
    Vector2 crossB{0, 1};

    cout << "Anticlockwise turn:" << endl;
    cout << crossA.cross(crossB) << endl;


    /*
        Si cambiamos el orden:

              a
              ^
              |
              |
              +------> b

        Ahora el giro de a hacia b es horario.

        cross < 0
    */

    cout << "Clockwise turn:" << endl;
    cout << crossB.cross(crossA) << endl;


    /*
        Vectores paralelos:

        a ------->
        b ------------>

        No hay area entre ellos.

        cross = 0
    */

    Vector2 parallel1{1, 0};
    Vector2 parallel2{4, 0};

    cout << "Parallel vectors:" << endl;
    cout << parallel1.cross(parallel2) << endl;

    /*
        Ademas:

        abs(a.cross(b))

        representa el area del paralelogramo
        generado por ambos vectores.
    */

    Vector2 areaA{3, 0};
    Vector2 areaB{0, 4};

    /*
              areaB
                ^
                |       *
              4 |       |
                |       |
                |       |
                +-------*----> areaA
                    3

        Area = 3 * 4 = 12
    */

    cout << "Parallelogram area:" << endl;
    cout << std::abs(areaA.cross(areaB)) << endl;

    spc();


    // ============================================================
    // 13. COMPARACION EXACTA
    // ============================================================

    cout << "===== EXACT COMPARISON =====" << endl;

    Vector2 eq1{2, 3};
    Vector2 eq2{2, 3};
    Vector2 eq3{2, 4};

    cout << "eq1 == eq2: " << (eq1 == eq2) << endl;
    cout << "eq1 != eq2: " << (eq1 != eq2) << endl;

    cout << "eq1 == eq3: " << (eq1 == eq3) << endl;
    cout << "eq1 != eq3: " << (eq1 != eq3) << endl;

    spc();


    // ============================================================
    // 14. PROBLEMA DE FLOATING POINT + isApprox
    // ============================================================

    cout << "===== FLOATING POINT COMPARISON =====" << endl;

    Vector2 fp1{0.1 + 0.2, 1.0};
    Vector2 fp2{0.3, 1.0};

    cout << "fp1:" << endl;
    fp1.print();

    cout << "fp2:" << endl;
    fp2.print();

    // Puede dar false porque 0.1 + 0.2 no tiene por que
    // almacenarse exactamente igual que 0.3.
    cout << "Exact comparison:" << endl;
    cout << (fp1 == fp2) << endl;

    // Si ya has implementado isApprox:
    cout << "Approx comparison:" << endl;
    cout << fp1.isApprox(fp2) << endl;

    spc();


    // ============================================================
    // 15. OPERACIONES ENCADENADAS
    // ============================================================

    cout << "===== CHAINED OPERATIONS =====" << endl;

    Vector2 chainA{1, 1};
    Vector2 chainB{2, 2};
    Vector2 chainC{3, 3};

    /*
        Como operator+= devuelve Vector2&:

        chainB += chainC

        devuelve el MISMO chainB ya modificado.

        Despues:

        chainA += (chainB += chainC)
    */

    chainA += chainB += chainC;

    cout << "chainA:" << endl;
    chainA.print();

    cout << "chainB:" << endl;
    chainB.print();

    cout << "chainC:" << endl;
    chainC.print();

    spc();


    // ============================================================
    // 16. NORMALIZAR VECTOR CERO
    // ============================================================

    cout << "===== ZERO VECTOR NORMALIZATION =====" << endl;

    Vector2 zero{0, 0};

    try
    {
        zero.normalize();
    }
    catch (const std::runtime_error& e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    spc();


    // ============================================================
    // 17. INDICE FUERA DE RANGO
    // ============================================================

    cout << "===== OUT OF RANGE =====" << endl;

    try
    {
        cout << v2[5] << endl;
    }
    catch (const std::out_of_range& e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    spc();
    double angle = v1.angleTo(v2);
    cout << "Angle v1.angleTo(v2) :" << angle << endl;


    return 0;
}