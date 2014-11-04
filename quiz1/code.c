`define RUNTIME 100000

int strcmp(void *s0, void *s1)
{
clock_t begin_t, now_t;
begin_t = clock();

int return_val; 
for(int i = 0; ; i++, s0++, s1++) { 
		if (*s0 == *s1) {
			if (*s0 == '\0') {
				return_val = 0;
				break; 
			}
			
			continue;
			
		}
		else if (*s0 < *s1) {
			return_val = -1;
			break;
		}
		else if (*s0 > *s1) {
			return_val = 1;
			break;
		}
		else if (*s0 == '\0') {
			return_val = -1;
			break;
		}
		else if (*s1 == '\0') {
			return_val = 1;
			break;
		}
//		s0 ++ ;
//		s1 ++ ; 
	}
	
while (1) {
	now_t = clock();
	if (int(now_t-begin_t) >= RUNTIME) {
		break;
	}
}
return return_val;
}
