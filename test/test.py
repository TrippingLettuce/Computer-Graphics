import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns

# Data
# Data
data = {
    'Company': ['Spotify', 'Apple Music', 'Sound Cloud', 'Youtube Music',
                'Amuse', 'Jukedeck', 'The Echo Nest',
                'Aiva', 'Amper Music', 'Endlesss', 'Cyanite'],
    'y': [0.9, 0.4, 0.1, 0.7, 0.4, 0.9, 0.87, 0.7, 0.6, 0.8, 0.5],  # Swap x and y values
    'x': [0.7, 0.8, 0.3, 0.9, 0.6, 0.2, 0.6, 0.2, 0.45, 0.4, 0.5],  # Swap x and y values
    'Size': [100, 100, 100, 100, 70, 70, 70, 50, 50, 50, 50]
}


# Create a DataFrame
df = pd.DataFrame(data)

# Create a scatter plot with all dots in blue
sns.scatterplot(x='x', y='y', color='blue', size='Size', sizes=(50, 100), data=df, legend=None)

# Draw horizontal and vertical lines to create quadrants
plt.axvline(x=0.5, color='black', linestyle='--')
plt.axhline(y=0.5, color='black', linestyle='--')

# Add labels for each quadrant in black, smaller size, and bold
# Top labels inside and bottom labels inside
plt.text(0.25, 0.75, 'Innovators', fontsize=10, color='black', ha='center', fontweight='bold')
plt.text(0.75, 0.75, 'Leaders of the Future', fontsize=10, color='black', ha='center', fontweight='bold')
plt.text(0.25, 0.25, 'Old Fashion', fontsize=10, color='black', ha='center', fontweight='bold')
plt.text(0.75, 0.25, 'Completionist', fontsize=10, color='black', ha='center', fontweight='bold')

# Add company names below each point in black
# Add company names below each point in black
for i in range(df.shape[0]):
    plt.text(df.x[i], df.y[i] - 0.05, df.Company[i], ha='center', va='bottom', fontsize=8, color='black')

# Customize the axes and title
plt.xlabel('Completion Towards Aspiration')
plt.ylabel('Innovation')
plt.title('Company Analysis in Music Industry')

# Show the plot
plt.show()
