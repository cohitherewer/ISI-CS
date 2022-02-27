struct mat{
  int arr[4];
};

program ADD_PROG {
	version ADD_VERS {
		struct mat ADD(mat) = 1;
	} = 1;
} = 0x23451111;
