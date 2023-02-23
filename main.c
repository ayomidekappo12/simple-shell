/* Populate environment list and read history */
	populate_env_list(info);
	read_history(info);

	/* Run shell */
	hsh(info, argv);

	return (EXIT_SUCCESS);
}
