const char *const	**g_env(void)
{
	static const char *const	*env;

	return (&env);
}
