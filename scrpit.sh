#!/bin/bash
#SBACHT --nodes=1               #numero de nós
#SBACHT --ntask-per-node=1      #numero de tarefa por nós 
#SBACHT --ntask=1               #numero total de tarefas MPI
#SBACHT --cpus-per-task=24      #numero de threads
#SBACHT -p cpu_dev              #fila (particao) a ser utilizada
#SBACHT -J teste                #nome da tarefa
#SBACHT --exclusive             #utilizacao exclusiva dos nós durante a execução da tarefa

#exibe os nós alocados para a tarefa
echo $SLURM_JOB_NODELIST

cd /Scrat/-caminho-da-pasta-que-quero-executar-o-programa

#configura compiladores
module load gcc/-versao-do-meu-gcc

srun -N 1 -nome-do-programa 24