void Tarjan ( int x ) {
         dfn[ x ] = ++dfs_num ;
         low[ x ] = dfs_num ;
         vis [ x ] = true ;//�Ƿ���ջ��
         stack [ ++top ] = x ;
         for ( int i=head[ x ] ; i!=0 ; i=e[i].next ){
                  int temp = e[ i ].to ;
                  if ( !dfn[ temp ] ){
                           Tarjan ( temp ) ;
                           low[ x ] = gmin ( low[ x ] , low[ temp ] ) ;
                 }
                 else if ( vis[ temp ])low[ x ] = gmin ( low[ x ] , dfn[ temp ] ) ;
         }
         if ( dfn[ x ]==low[ x ] ) {//����ǿ��ͨ����
                  vis[ x ] = false ;
                  color[ x ] = ++col_num ;//Ⱦɫ
                  while ( stack[ top ] != x ) {//���
                           color [stack[ top ]] = col_num ;
                           vis [ stack[ top-- ] ] = false ;
                 }
                 top -- ;
         }
}
