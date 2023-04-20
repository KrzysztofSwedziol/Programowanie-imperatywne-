#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REL_SIZE 100
#define MAX_RANGE 100

typedef struct {
	int first;
	int second;
} pair;

// Add pair to existing relation if not already there
int add_relation (pair*, int, pair);

// Case 1:

// The relation R is reflexive if xRx for every x in X
int is_reflexive(pair*, int);

// The relation R on the set X is called irreflexive
// if xRx is false for every x in X
int is_irreflexive(pair*, int);

// A binary relation R over a set X is symmetric if:
// for all x, y in X xRy <=> yRx
int is_symmetric(pair*, int);

// A binary relation R over a set X is antisymmetric if:
// for all x,y in X if xRy and yRx then x=y
int is_antisymmetric(pair*, int);

// A binary relation R over a set X is asymmetric if:
// for all x,y in X if at least one of xRy and yRx is false
int is_asymmetric(pair*, int);

// A homogeneous relation R on the set X is a transitive relation if:
// for all x, y, z in X, if xRy and yRz, then xRz
int is_transitive(pair*, int);

// Case 2:

// A partial order relation is a homogeneous relation that is
// reflexive, transitive, and antisymmetric
int is_partial_order(pair*, int);

// A total order relation is a partial order relation that is connected
int is_total_order(pair*, int);

// Relation R is connected if for each x, y in X:
// xRy or yRx (or both)
int is_connected(pair*, int);

int find_max_elements(pair*, int, int*);
int find_min_elements(pair*, int, int*);
int get_domain(pair*, int, int*);

// Case 3:

int composition (pair*, int, pair*, int, pair*);

// Comparator for pair
int cmp_pair (const void *a, const void *b) {
}

int insert_int (int *tab, int n, int new_element) {
}

// Add pair to existing relation if not already there
int add_relation (pair *tab, int n, pair new_pair) {
    for (int i = 0; i<n; i++) {
        if (tab[i].first == new_pair.first && tab[i].second == new_pair.second) {
            return 0;
        }

    }
    tab[n]=new_pair;
    return 1;
}

// Read number of pairs, n, and then n pairs of ints
int read_relation(pair *relation) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        pair p;
        scanf("%d %d", &p.first, &p.second);
        if (add_relation(relation, i, p)) {
            // Pair was added to relation
            continue;
        } else {
            // Pair already exists in relation, ignore it
            n--;
        }
    }
    return n;

}

void print_int_array(int *array, int n) {
    printf("%d", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int is_reflexive(pair *relation, int size){
    int flag = 0;
    int curr_num = 0;
    for(int i=0; i<size; i++){
        curr_num = relation[i].first;
        for(int j=0; j<size; j++){
            if(relation[j].first == curr_num && relation[j].second == curr_num){
                flag = 1;
                break;
            }

        }
        if(flag == 0){
            return 0;
        }
        else{
            flag = 0;
        }

    }
    flag = 0;
    curr_num = 0;
    for(int i=0; i<size; i++){
        curr_num = relation[i].second;
        for(int j=0; j<size; j++){
            if(relation[j].first == curr_num && relation[j].second == curr_num){
                flag = 1;
                break;
            }

        }
        if(flag == 0){
            return 0;
        }
        else{
            flag = 0;
        }

    }

    return 1;


}

int is_irreflexive(pair *relation, int size){
    int flag = 0;
    int curr_num = 0;
    for(int i=0; i<size; i++){
        curr_num = relation[i].first;
        for(int j=0; j<size; j++){
            if(relation[j].first == curr_num && relation[j].second == curr_num){
                flag = 1;
                break;
            }

        }
        if(flag == 1){
            return 0;
        }
        else{
            flag = 0;
        }

    }
    flag = 0;
    curr_num = 0;
    for(int i=0; i<size; i++){
        curr_num = relation[i].second;
        for(int j=0; j<size; j++){
            if(relation[j].first == curr_num && relation[j].second == curr_num){
                flag = 1;
                break;
            }

        }
        if(flag == 1){
            return 0;
        }
        else{
            flag = 0;
        }

    }

    return 1;

}
int is_symmetric(pair *relation, int size){
    int curr_num1 = 0;
    int curr_num2 = 0;
    int flag = 0;
    for(int i=0; i<size; i++){
        curr_num1 = relation[i].first;
        curr_num2 = relation[i].second;
        for(int j = 0; j<size; j++){
            if(relation[j].first == curr_num2 && relation[j].second == curr_num2){
                flag = 1;
                break;
            }
            if(flag == 0){
                return 0;
            }
            else{
                flag = 0;
            }
        }
    }
    return 1;
}
int is_antisymmetric(pair *relation, int size){
    int curr_num1 = 0;
    int curr_num2 = 0;
    int flag = 0;
    for(int i=0; i<size; i++){
        curr_num1 = relation[i].first;
        curr_num2 = relation[i].second;
        for(int j = 0; j<size; j++){
            if(relation[j].first == curr_num2 && relation[j].second == curr_num2){
                flag = 1;
                break;
            }
            if(flag == 1){
                if(curr_num2!=curr_num1){
                    return 0;
                }
            }
            else{
                flag = 0;
            }
        }
    }
    return 1;

}

int is_asymmetric(pair *relation, int size) {
    int curr_num1 = 0;
    int curr_num2 = 0;
    int flag = 0;
    for (int i = 0; i < size; i++) {
        curr_num1 = relation[i].first;
        curr_num2 = relation[i].second;
        for (int j = 0; j < size; j++) {
            if (relation[j].first == curr_num2 && relation[j].second == curr_num2) {
                flag = 1;
                break;
            }
            if(flag == 1){
                return 0;
            }
        }
    }
    return 1;
}
int is_transitive(pair *relation, int size){
    int x = 0;
    int y = 0;
    int z = 0;
    int flag = 0;
    for(int i=0; i<size; i++){
        x = relation[i].first;
        y = relation[i].second;
        for(int j = 0; j < size; j++){
            if(relation[j].first == y){
                z = relation[j].second;
                for(int k=0; k<size; k++){
                    if(relation[k].first == x && relation[k].second == z){
                        flag = 1;
                    }

                }
                if(flag == 0){
                    return 0;
                }else{
                    flag = 0;
                }
            }
        }
    }
    return 1;
}

int is_partial_order(pair *relation, int size){
    if(is_reflexive(relation, size) == 1&& is_transitive(relation, size)==1 && is_antisymmetric(relation, size) ==1){
        return 1;
    }
    return 0;
}
int is_connected(pair *relation, int size){


}
int is_total_order(pair *relation, int size){
    if (is_partial_order(relation, size) && is_connected(relation, size)) {
        return 1;
    }
    return 0;

}

int find_max_elements(pair *relation, int size, int *Max_Elements){
    int curr_element = 0;
    int counter = 0;
    int flag = 1;
    for(int i=0; i<size; i++){
        curr_element = relation[i].first;
                for(int j=0; j<size; j++){
                    if(relation[j].first==curr_element && relation[j].second!=curr_element){
                        flag = 0;
                        break;
                    }
                }
                if(flag == 0){
                    flag = 1;
                }
                else{
                    Max_Elements[counter] = curr_element;
                    counter +=1;
                }
    }
    for(int i=0; i<size; i++){
        curr_element = relation[i].second;
        for(int j=0; j<size; j++){
            if(relation[j].first==curr_element && relation[j].second!=curr_element){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            flag = 1;
        }
        else{
            Max_Elements[counter] = curr_element;
            counter +=1;
        }
    }
    return 1;

}

int find_min_elements(pair *relation, int size, int *Min_Elements){
    int curr_element = 0;
    int counter = 0;
    int flag = 1;
    for(int i=0; i<size; i++){
        curr_element = relation[i].first;
        for(int j=0; j<size; j++){
            if(relation[j].second==curr_element && relation[j].first!=curr_element){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            flag = 1;
        }
        else{
            Min_Elements[counter] = curr_element;
            counter +=1;
        }
    }
    for(int i=0; i<size; i++){
        curr_element = relation[i].second;
        for(int j=0; j<size; j++){
            if(relation[j].second==curr_element && relation[j].first!=curr_element){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            flag = 1;
        }
        else{
            Min_Elements[counter] = curr_element;
            counter +=1;
        }
    }
    return 1;

}

int valueinarray(float val, float *arr){
    int i;
    for(i = 0; i < sizeof(arr); i++){
        if(arr[i] == val) return 1;
    }
    return 0;
}

int get_domain(pair *relation, int size, int *domain){
    int counter;
    int curr_num;
    for(int i=0; i<size; i++){
        curr_num = relation[i].first;
        if(valueinarray(curr_num, domain) == 0){
            domain[counter] = curr_num;
            counter++;
        }

    }
}

int composition (pair *relation1, int size1, pair *relation2, int size2, pair *result){
    int x;
    int y;
    int counter = 0;
    for(int i=0; i<size1; i++){
        x = relation1[i].first;
        y = relation1[i].second;
        for(int j=0; j<size2; j++){
            if(relation2[j].first == y){
                pair res;
                res.first = x;
                res.second = relation2[j].second;
                result[counter]=res;
                counter++;
            }
        }
    }
    return 1;

}


int main(void) {
	int to_do;
	pair relation[MAX_REL_SIZE];
	pair relation_2[MAX_REL_SIZE];
	pair comp_relation[MAX_REL_SIZE];
	int domain[MAX_REL_SIZE];
	int max_elements[MAX_REL_SIZE];
	int min_elements[MAX_REL_SIZE];

	scanf("%d",&to_do);
	int size = read_relation(relation);
	int ordered, size_2, n_domain;

	switch (to_do) {
		case 1:
			printf("%d ", is_reflexive(relation, size));
			printf("%d ", is_irreflexive(relation, size));
			printf("%d ", is_symmetric(relation, size));
			printf("%d ", is_antisymmetric(relation, size));
			printf("%d ", is_asymmetric(relation, size));
			printf("%d\n", is_transitive(relation, size));
			break;
		case 2:
			ordered = is_partial_order(relation, size);
			n_domain = get_domain(relation, size, domain);
			printf("%d %d\n", ordered, is_total_order(relation, size));
			print_int_array(domain, n_domain);
			if (!ordered) break;
			int no_max_elements = find_max_elements(relation, size, max_elements);
			int no_min_elements = find_min_elements(relation, size, min_elements);
			print_int_array(max_elements, no_max_elements);
			print_int_array(min_elements, no_min_elements);
			break;
		case 3:
			size_2 = read_relation(relation_2);
			printf("%d\n", composition(relation, size, relation_2, size_2, comp_relation));
			break;
		default:
			printf("NOTHING TO DO FOR %d\n", to_do);
			break;
	}
	return 0;
}