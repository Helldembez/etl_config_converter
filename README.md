#etl-config-converter
###Enemy Territory: Legacy config converter
This program converts a ETPro config to a legacy compatible config. It does this by mapping the ETPro/2.60b cvars to the legacy variant.
If there is no viable mapping the cvar gets deleted from the config. This convert creates a new file with the '-converted' postfix to the filename as name.

```
Useable options:
etl_config_converter                   : Running without any arguments will display this help output.
etl_config_converter -h                : Will display this help output.
etl_config_converter Autoexec.cfg      : A path to the filename or the filename itself to parse.
etl_config_converter -a                : Instead of specifying a file to convert it will convert all '.cfg' files in the current directory.
```
###Mapping
Some cvars can not be 1-on-1 mapped. 
Values of cvars such as `b_noactivatelean` to `cl_activatelean` need to be inverted. 
Where the values of `b_tracers` to `cg_tracers` need to be mapped to a completely different value instead. 
This converter takes care of those things, but still can't convert all values.

For example cvars such as `b_locationMaxChars` is not 100% equivalent to `cg_locationMaxChars`.
The ETPro variant counts color code characters as part of the string, while legacy ignores them. 
So the string `^1foo` with a `maxChars` of `3` is `f` in ETPro, but `foo` in legacy. 

For cvars such as these there will be comments in the config and CLI output to inform the user of the effect.

###New cvars
ET:Legacy also offers new useful cvars that ETPro players might not be aware of. 
For this reason there will be another informational comment block added to the top of the convered config.