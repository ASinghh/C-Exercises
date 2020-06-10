#include <glob.h>

glob_t glob_result;
glob("/your_directory/*",GLOB_TILDE,NULL,&glob_result);
for(unsigned int i=0; i<glob_result.gl_pathc; i++){
  cout << glob_result.gl_pathv[i] << endl;
}
