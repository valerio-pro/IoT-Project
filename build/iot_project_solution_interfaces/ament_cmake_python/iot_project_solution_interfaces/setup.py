from setuptools import find_packages
from setuptools import setup

setup(
    name='iot_project_solution_interfaces',
    version='0.0.1',
    packages=find_packages(
        include=('iot_project_solution_interfaces', 'iot_project_solution_interfaces.*')),
)
