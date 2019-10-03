void Tarjan ( int x ) {
         dfn[ x ] = ++dfs_num ;
         low[ x ] = dfs_num ;
         vis [ x ] = true ;//是否在栈中
         stack [ ++top ] = x ;
         for ( int i=head[ x ] ; i!=0 ; i=e[i].next ){
                  int temp = e[ i ].to ;
                  if ( !dfn[ temp ] ){
                           Tarjan ( temp ) ;
                           low[ x ] = gmin ( low[ x ] , low[ temp ] ) ;
                 }
                 else if ( vis[ temp ])low[ x ] = gmin ( low[ x ] , dfn[ temp ] ) ;
         }
         if ( dfn[ x ]==low[ x ] ) {//构成强连通分量
                  vis[ x ] = false ;
                  color[ x ] = ++col_num ;//染色
                  while ( stack[ top ] != x ) {//清空
                           color [stack[ top ]] = col_num ;
                           vis [ stack[ top-- ] ] = false ;
                 }
                 top -- ;
         }
}
