#!/bin/bash
for i in `seq 1 30`;
        do
                ./a.out <../Graphs/gcol$i.txt >../GraphsUndirectedDynamic/gcol$i.txt
        done