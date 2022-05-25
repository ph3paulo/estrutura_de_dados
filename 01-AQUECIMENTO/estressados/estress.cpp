#include "funcoes.h"

int main()
{
    existe({-1, -50, -99}, -1);
    existe({-1, -50, -99}, 10);
    

    contar({-1, -50, -1, -99}, -1);
    contar({-1, -50, -1, -99}, 10);

    procurar({-1, -50, -1 -99}, -50);
    procurar({-1, -50, -1, -99}, 10);

    procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 0);
    procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 3);
    procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 4);

    procurar_menor({5, 3, -1, -50, -1, -99});

    procurar_pos_menor({5, 3, -1, -50, -1, -99});

    procurar_pos_menor_apartir({5, 3, -1, -50, -1, 10}, 3);

    procurar_melhor_pos_se({5, 3, -1, -50, -1, -99});
    procurar_melhor_pos_se({-1, -50, -1, -99});

    calcular_stress_medio({-1, -50, -1, -99});

    mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99});
    mais_homens_ou_mulheres({5, 3, 1, -50, -1, -99});
    mais_homens_ou_mulheres({5, 3, 1, -50, -1, 99});

    qual_metade_eh_mais_estressada({5, 3, -1, -50, -1, -99});
    qual_metade_eh_mais_estressada({50, 98, 2, -50, -1, -99});
    qual_metade_eh_mais_estressada({-51, 99, 1, -50, -1, -99});

    homens_sao_mais_estressados_que_mulheres({1,2,3,-5,-6,-7});
    homens_sao_mais_estressados_que_mulheres({-1,-2,-3,5,6,7});
    homens_sao_mais_estressados_que_mulheres({-7,-6,-5,5,6,7});

    //BLOCO 2;

    clonar({1,2,3,4});

    pegar_homens({1,2,3,-5,-6,-7});

    pegar_mulheres({1,2,3,-5,-6,-7});

    pegar_calmos({1,2,3,-5,-6,-7});

    pegar_mulheres_calmas({1,2,3,-5,-6,-7});

    inverter_com_copia({1,2,3,-5,-6,-7});

    inverter_inplace({1,2,3,-5,-6,-7});

    sortear({1,2,3,-5,-6,-7});

    ordenar({1,5,3,4,6,7,2});

    exclusivos({1,5,3,4,6,7,2});

    //BLOCO 3

    ocorrencias({1, 3, 4, 3, 1, -3, -3});

}