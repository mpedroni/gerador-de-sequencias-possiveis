void gerarCombinacoes(int userInputs[], int sequencias[][J], int qtdeCombinPossiveis, int qtdeInputs) {
    int currentComparedNumber;

    int nullPosition0 = 6;
    int nullPosition1 = 7;
    int nullPosition2 = 8;
    int nullPosition3 = 9;

    for(int i = 0; i < qtdeCombinPossiveis; i++) {
        sequencias[i][0] = i + 1; // Atribui um id para cada combinação

        currentComparedNumber = 0;

        for(int j = 1; j < J; j++) { // j = 1 pois j = 0 é o id das sequencias
            for(int jCombin = 0; jCombin < 10; jCombin++) {
                if(jCombin == currentComparedNumber && userInputs[jCombin] != 0 && jCombin != nullPosition0 && jCombin != nullPosition1 && jCombin != nullPosition2 && jCombin != nullPosition3) {
                    sequencias[i][j] = userInputs[jCombin];
                    break;
                }
            }
            if(sequencias[i][j] == 0)
                j--;
            currentComparedNumber++;
        }

        if(nullPosition0 != 0)  {
            nullPosition0--;

        } else if(nullPosition1 != 1 && qtdeInputs >= 8) {
            nullPosition1--;
            nullPosition0 = nullPosition1 - 1;

        } else if(nullPosition2 != 2 && qtdeInputs >= 9) {
            nullPosition2--;
            nullPosition1 = nullPosition2 - 1;
            nullPosition0 = nullPosition2 - 2;

        } else if(nullPosition3 != 3 && qtdeInputs == 10) {
            nullPosition3--;
            nullPosition2 = nullPosition3 - 1;
            nullPosition1 = nullPosition3 - 2;
            nullPosition0 = nullPosition3 - 3;
        }
    }
}
