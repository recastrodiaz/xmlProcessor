<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
	<html>
		<body>
			<xsl:apply-templates/>
		</body>
	</html>
</xsl:template>

<xsl:template match="rapport">
	<h2>Titre : <xsl:value-of select="titre"/></h2>
	<p> Resumé : <xsl:value-of select="resume"/></p>
	<xsl:apply-templates/>
</xsl:template>

<xsl:template match="auteur">
	<p>Auteur(s) :</p> 
	<p><xsl:value-of select="prenom"/> <xsl:value-of select="nom"/></p>
</xsl:template>

<xsl:template match="chapitre">
	<p>Chapitres</p> 
	<h3><xsl:value-of select="titre"/></h3>
	<xsl:apply-templates/>
</xsl:template>

<xsl:template match="section">
	<p>Section :</p> 
	<h4><xsl:value-of select="titre"/></h4>
	<p><xsl:value-of select="p"/></p>
</xsl:template>

<xsl:template match="titre">
</xsl:template>

<xsl:template match="resume">
</xsl:template>

</xsl:stylesheet> 