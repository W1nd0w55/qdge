from argparse import ArgumentParser
from sys import argv
from os import system as run
from pathlib import Path
from shutil import rmtree
from platform import system

cwd = Path(__file__).resolve().parent

def generate(build_system: str) -> None:
    try: rmtree(f'{cwd}/build/')
    except FileNotFoundError: pass
    except PermissionError:
        print('''Permission denied to delete build folder.
Unless you delete it yourself, the build files will be overwritten.
''')

    run(f'cmake -G "{build_system}" -S {cwd}/ -B {cwd}/build/')

def main() -> None:
    parser = ArgumentParser(prog = argv[0],
        description = 'This script generates project files for qdge.',)
    
    parser.add_argument('-b', '--build-system')
    args = parser.parse_args()

    match args.build_system:
        # Visual Studio
        case 'vs2022': generate('Visual Studio 17 2022')
        case 'vs2019': generate('Visual Studio 16 2019')
        case 'vs2017': generate('Visual Studio 15 2017')
        case 'vs2015': generate('Visual Studio 14 2015')

        # Make
        case 'borland_make': generate('Borland Makefiles')
        case 'nmake': generate('NMake Makefiles')
        case 'nmake_jom': generate('NMake Makefiles JOM')
        case 'msys_make': generate('MSYS Makefiles')
        case 'mingw_make': generate('MinGW Makefiles')
        case 'unix_make': generate('Unix Makefiles')

        case 'ninja': generate('Ninja')
        case 'ninja-multi': generate('Ninja Multi-Config')
        case 'watcom-wmake': generate('Watkom WMake')

        case None: generate('Visual Studio 17 2022'
            if system() == 'Windows' else 'Unix Makefiles')


if __name__ == '__main__':
    main()
